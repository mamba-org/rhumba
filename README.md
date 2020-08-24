# ¡Caramba! R bindings to Mamba! 🐍⬛️

In early stages of development, but pretty usable.

⚠️ACHTUNG!⚠️ It's necessary to build mamba from source with the master branch to use it.

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

You can use Mamba as your new package manager.

Set the channel you'd rather use:

`mamba::set_channels(c("conda-forge", "default"))`

Try installing something:

`mamba::install("xtensor")`

You might need to setup your `MAMBA_ROOT_PREFIX` if you've never done it before.
You can do that by calling:

`mamba::set_root_prefix(/path/to/prefix)`

Or use  micromamba shell init ... to initialize your shell, then restart.

## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the LICENSE file for details.