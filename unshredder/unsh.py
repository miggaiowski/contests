from PIL import Image
import sys
import random

class strip:
    left = []
    right = []
    original_strips = []

    def __init__(self, l, r, os=[]):
        self.left, self.right = l, r
        self.original_strips = os
    
    # def __cmp__(self, other):
    #     return self.left[0] > other.left[0]

    def __unicode__(self):
        return "\n".join(map(str, zip(self.left, self.right)))
    
    def __str__(self):
        return self.__unicode__()

image = Image.open(sys.argv[1])
data = image.getdata() # This gets pixel data

# Access an arbitrary pixel. Data is stored as a 2d array where rows are
# sequential. Each element in the array is a RGBA tuple (red, green, blue,
# alpha).

def get_pixel_value(x, y):
   width, height = image.size
   pixel = data[y * width + x]
   return pixel

width, height = image.size
NUMBER_OF_STRIPS = width / 32

strips = []
for s in xrange(NUMBER_OF_STRIPS):
    left = []
    right = []
    for i in xrange(height):
        left.append(get_pixel_value(s * 32, i))
        right.append(get_pixel_value(s * 32 + 31, i))
    strips.append(strip(left,right, [s,]))

# print strips[0]

def create_image(original, permutation):
    # Create a new image of the same size as the original
    # and copy a region into the new image
    unshredded = Image.new("RGBA", original.size)
    strip_width = unshredded.size[0]/NUMBER_OF_STRIPS
    for pos, strip_number in enumerate(permutation):
        x1, y1 = strip_width * strip_number, 0
        x2, y2 = x1 + strip_width, height
        source_region = original.crop((x1, y1, x2, y2))
        destination_point = (pos * strip_width, 0)
        unshredded.paste(source_region, destination_point)
    # Output the new image
    # unshredded.save("unshredded" + str(permutation[0]) + '-' + str(permutation[1]) + ".jpg", "JPEG")
    unshredded.save("unshredded.jpg", "JPEG")

def norma(x):
    return sum(map(lambda x:x*x, x))

def diff(s1, s2):
    return sum(map(lambda x: abs(x[1]-x[0]), zip(map(norma, s2.left), map(norma, s1.right))))
    
def method1():
    pairs = []
    for i1, s1 in enumerate(strips):
        best = 999999999999
        best_pair = -1
        for i2, s2 in enumerate(strips):
            if s1 != s2:
                curr = diff(s1, s2)
                if curr < best:
                    best = curr
                    best_pair = i2
        pairs.append(((i1, best_pair), best))

    # Remove the worst pair
    worst = pairs[0]
    for p in pairs:
        if p[1] > worst[1]:
            worst = p
    pairs.remove(worst)

    # Print the pairs
    for p in pairs:
        print p
        create_image(image, p[0])

def method2(strips):
    while len(strips) > 1:
        print len(strips), "passos faltando\r",
        sys.stdout.flush()
        the_best = 256**4
        for i1, s1 in enumerate(strips):
            best = 255**4
            best_i2 = -1
            for i2, s2 in enumerate(strips):
                if i1 != i2:
                    curr = diff(s1, s2)
                    if curr < best:
                        best = curr
                        best_i2 = i2
            if best < the_best:
                pair = (i1, best_i2)
                the_best = best
        s1 = strips[pair[0]]
        s2 = strips[pair[1]]
        s = strip(s1.left, s2.right, s1.original_strips + s2.original_strips)
        strips.remove(s1)
        strips.remove(s2)
        strips.append(s)
        # print s1.original_strips
        # print s2.original_strips
        # print s.original_strips
        # print "--"
        # for s in strips:
        #     print s.original_strips
        # print
        # print "*********************"
        # print 
    print strips[0].original_strips
    create_image(image, strips[0].original_strips)
        
method2(strips)

# perm = range(NUMBER_OF_STRIPS)
# random.shuffle(perm)
# create_image(image, perm)
