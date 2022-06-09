import math
import matplotlib.pyplot as plt
import numpy as np

SHOW_ITERATIONS = False


def solve(f, df, x0, e, dx, maxIterations):
    iterations = []
    i = 0

    prev = x0
    root = x0
    #iterations.append([i, abs(root-prev)])
    root = x0 - f(x0) / df(x0, dx, f)
    i += 1
    iterations.append([i, abs(root-prev)])

    while abs(prev-root) > e and i <= maxIterations:
        prev = root
        root = prev - f(prev) / df(prev, dx, f)
        i += 1
        iterations.append([i, abs(root-prev)])

    iter_nums = []
    iter_roots = []

    for iteration in iterations:
        iter_nums.append(iteration[0])
        iter_roots.append(iteration[1])
    print(root, i, dx)
    return root, i, iter_nums, iter_roots


def function1(x):
    result = 5*x**4 - 4*x**3 - 2*x**2 + 3*x + 1
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def function2(x):
    result = np.sin(3*x)+x**2
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def function3(x):
    result = np.sin(x**3) * np.cos(x**5) + x
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def function4(x):
    result = 1/x - x + np.sin(5*x)
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def function5(x):
    result = np.log(x/2)/(2*x**3) - (x**4)/4 - x**2 + 16
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def function6(x):
    result = ((np.exp(x)-1)*np.arctan(x+np.pi))/(np.sin(x)+np.pi)
    if SHOW_ITERATIONS:
        print("f =", result)
    return result


def dfunction(x, dx, function):
    result = (function(x+dx) - function(x)) / dx
    if SHOW_ITERATIONS:
        print("df =", result)
    return result


dx = float(input())
x0 = float(input())
accuracy = float(input())
maxIterations = int(input())


#plt.axhline(y=0, color="black", linestyle="-")
plt.axhline(y=0, color="black", linestyle="-")
#plt.axhline(y=accuracy, color="grey", linestyle=":")
#plt.axhline(y=-accuracy, color="grey", linestyle=":")
plt.axhline(y=0, color="black", linestyle="--")

functions = [function1, function2, function3, function4, function5, function6]
labels = [r"$f(x) = 5x^4 - 4x^3 - 2x^2 + 3x + 1", r"$f(x) = sin(3x) + x^2",
          r"$f(x) = sin(x^3) + cos(x^5) + x", r"$f(x) = \frac{1}{x} - x + sin(5-x)", r"$f(x) = \frac{ln(\frac{x}{2})}{2x^3} - \frac{x^4}{4} - x^2 + 16", r"$f(x) = \frac{(e^x-1)actg^{-1}(x+\pi)}{sinx+\pi}"]

minrange = 0.0000001
maxrange = 100
for k in range(len(functions)):
    if k == 3 or k == 2:
        continue
    epentrys = np.linspace(minrange, maxrange, 512)
    iters = []
    for epentry in epentrys:
        #x = np.linspace(minrange, maxrange, 10001)
        #y = dfunction(x, d, functions[k])
        root, i, x, y = solve(functions[k], dfunction, x0,
                              epentry, dx, maxIterations)
        if not (i == 101):
            iters.append(i)
        else:
            if(len(iters)-1 < 0):
                iters.append(0)
            else:
                iters.append(iters[len(iters)-1])
    #s = [16.0 for n in range(len(dxentrys))]
    # if(i == 101 or root == np.nan):
    #
    # else:
    plt.plot(
        epentrys, iters, '-', label=labels[k] + "$")  # , label="N = " + str(i))  # + "; x = " + "{:.4f}".format(root))
plt.xscale('log')
plt.minorticks_on()
plt.mi
#plt.title(labels[k]+"$", fontsize=14.0)
#plt.xticks(np.linspace(minrange, maxrange, 100))

# root, i, iter_nums, iter_roots = solve(functions[k], dfunction, x0,
#                                       accuracy, dx, maxIterations)
#print("root =", root, "iterations =", i)
# plt.plot(iter_nums, iter_roots, 'o', linewidth=2,
#         label=labels[k] + ";" + "$")
plt.xlim(left=0.1)  # iter_nums[len(iter_nums)-1])
plt.ylim(bottom=0)
plt.xlabel(r'$\epsilon$', fontsize=14.0)
plt.ylabel(r'$N$')
plt.legend(fontsize=14.0)
plt.show()
