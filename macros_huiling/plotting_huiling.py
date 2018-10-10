import math
from numpy import linspace
from scipy.integrate import quad
from scipy.special import j0
from matplotlib import pyplot

def j0i(x):
    """Integral form of J_0(x)"""
    def integrand(phi):
        return math.cos(x * math.sin(phi))
    return (1.0 / math.pi) * quad(integrand, 0, math.pi)[0]

def J0_plot():
    """Sample J0 at linspace(0, 20, 200)"""
    x = linspace(0, 20, 200)
    y = j0(x)
    x1 = x[::10]
    y1 = map(j0i, x1)
    pyplot.plot(x, y, label=r'$J_0(x)$')
    pyplot.plot(x1, y1, 'ro', label=r'$J_0^{integ}(x)$')
    pyplot.title(
        r'Verify $J_0(x)=\frac{1}{\pi}\int_0^{\pi}\cos(x \sin\phi)\,d\phi$')
    pyplot.xlabel('$x$')
    pyplot.legend()

def random_image():
    """Shows a random image 32x32"""
    img = numpy.random.rand(32, 32)
    pyplot.matshow(img)
    
j0i(32)
J0_plot()
random_image()
