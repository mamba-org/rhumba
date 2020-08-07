# ¡Caramba! R bindings to Mamba! 🐍⬛️

⚠️!ACHTUNG!⚠️

Currently under development. You need to download your own version of mamba, add the following on th `Cmakelists.txt` file and compile by yourself.

```
+# HACKS!
+add_library(mamba_lib SHARED ${MAMBA_SOURCES})
+install(TARGETS mamba_lib)
```

Once it's done, include the path for mamba libs in your `src/Makevars.in`.

```
-I/yourpathto/mamba/include
```

## Installation

### Requirements:

First make sure to have the following R packages:

- Rcpp
- Devtools

#### Windows, Mac and Linux:

devtools::install_github("hadley/devtools")

```
install.packages("Rcpp")
install.packages("devtools")
```

### Setup:

Inside the R environment, first generate the bidinings required to call C++ functions from R functions adorned with `Rcpp::export`:

`Rcpp::compileAttributes()`

Then:

`devtools::install()`

And you're ready to use Mamba!

## Use

You can use Mamba as your new package manager. Try installing something:

`mamba::install("xtensor")`

You might need to setup your `MAMBA_ROOT_PREFIX` if you've never done it before.
You can do that by calling:

`mamba::set_root_prefix(/path/to/prefix)`

Or either set the `MAMBA_ROOT_PREFIX` environment variable, or use  micromamba
shell init ... to initialize your shell, then restart or source the contents of the shell init script.

## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the LICENSE file for details.