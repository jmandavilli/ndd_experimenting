# need to format so it is more like skilearn
# use more sklearn functions, a lot of these things are probably already there in sklearn
# tried using pytest
# neeed to add test configuration to use pytest (got this from pytest documetnation)

import pytest
import ObliqueForest
import numpy as np

def pytest_addoption(parser):
    parser.addoption("--all", action="store_true", help="run all combinations")
    

def pytest_generate_tests(metafunc):
    if 'param' in metafunc.fixturenames:
        if metafunc.config.option.all:
            end = 5
        else:
            end = 2
        metafunc.parameterize("param", range(end))


def ObliqueTreeTest(param):
    x = np.random.rand(23,15) # mimicing sklearns tree tests and data
    y = np.zeros(23)
    y[5] = 1
    y[10] = 1
    y[15] = 1
    y[20] = 1
    otree = ObliqueTree()
    otree.fit(x,y)
    results = o.predict(x)
    sum = 0
    for i in range(len(y)):
        if not (y[i] = predict[i]):
            sum += 1
    sum /= len(y) 
    assert(np.sqrt(sum) > 0.9)
    assert(param < 4) # unecessary for this test but using to learn how to use pytest for paramaterizing tests


ObliqueTreeTest()
