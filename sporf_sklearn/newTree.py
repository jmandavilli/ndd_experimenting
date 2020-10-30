# importing from sklearn right now but once able to work on fork
# will change so not importing anymore and using actual references
from ._oblique import tree # will be in c and linked with Cython
from sklearn.base import ClassifierMixin
from sklearn.base import BaseEstimator

class ObliqueTree(BaseEstimator):
    def __init__(self, splitter = "oc1, axis_parallel", random_state = 1):
        self.splitter = splitter
        self.tree = Tree(splitter = self.splitter)

    def fit(self, x, y):
        x = check_X_y(x,y)[0]
        y = check_X_y(x,y)[1]
        self.classes = y;
        self.tree.fit(x,y, self.splitter)

    def predict(self, x):
        return self.tree.predict(x)
         

class ObliqueNode(Node):
    # changing the nodes for our tree so it can accept oblique splits

# found some online resources as well as some helpful frameworks
