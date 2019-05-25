# Minimal code for reproduction of failing span_test with Visual Studio 2019

A small bug reproduction of a unit test that fail when executed with Visual Studio 2019 (as of 2019-05-25). Works fine in debug build or VS 2018.

I suspect that the issue is caused by the new memmove intrinsic (could also be some Undefined Behavior I'm not seeing):
- test pass if memmove is called via a function pointer
- test pass if size passed to memmove is large (change array size to 50 and number of items to move accordingly)

## Release build output:

```
Before:   10, 20, 30, 40, 50,
After:    10, 20, 20, 30, 30,
Expected: 10, 20, 20, 30, 40,

FAILED!
```

## Debug build output:

```
Before:   10, 20, 30, 40, 50,
After:    10, 20, 20, 30, 40,
Expected: 10, 20, 20, 30, 40,

OK
```

## Problem on Microsoft Developer Community

https://developercommunity.visualstudio.com/content/problem/583227/vs-2019-cl-1921277022-memmove-instrinsic-optimizat.html

Baptiste Lepilleur.
