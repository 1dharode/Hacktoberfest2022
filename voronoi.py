""" Imports """
import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial import KDTree
from PIL import Image

""" Voronoi """
def voronoi(x, y, cells):
    # initialize points and colours
    col = np.random.randint((50, 200, 256), size=(cells, 3), dtype=np.uint8) # random colors
    pts = np.random.randint((y, x), size=(cells, 2))

    # get all possible coordinates + reshape into coordinate pairs
    coord = np.moveaxis(np.indices((y, x)), 0, -1).reshape((-1, 2))

    # find closest point (from pts) to each coordinate pixel using KDTree algo
    _t, pix = KDTree(pts).query(coord)
    pix = pix.reshape((y, x))

    # note: we had inverted x and y throughout because in NumPy indexing, the first dimension is for y and second is for x
    # image save and show
    plt.imsave("voronoi.png", col[pix])
    plt.show()

# test
voronoi(500, 300, 250)
