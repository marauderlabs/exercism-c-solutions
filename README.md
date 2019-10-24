# exercism-c-solutions
Solutions to the C track exercises at exercism.io
These exercises employ the [Unity UTF][1] (Unit Test Framework)

#### How to run?
`make` or `make test` in the solution direction to build and execute the test cases.

#### Note:
Create a symbolic link to the `vendor` directory, inside the test dirs of every solution, if it doesn't already exist,
to build the solutions and test them.
This directory of Unity UTF has been factored out to avoid duplicates of the same files in every solution

```
cd core/1-hello-world/test/
ln -s ../../../vendor vendor
```
Then, for builds, change to the exercise directory
```
cd ..
make test
```


[1]: https://github.com/ThrowTheSwitch/Unity
