# Rhumba 🐍

¡Caramba! R bindings to Mamba!

In early stages of development, but pretty usable.

## Installation

With either mamba or conda:

`mamba install rhumba`

`conda install rhumba`

## Use

You can use Mamba as your new package manager.

Set the channel you'd rather use:

`rhumba::set_channels(c("conda-forge", "default"))`

Try installing something:

`rhumba::install("xtensor")`

You might need to setup your `MAMBA_ROOT_PREFIX` if you've never done it before.
You can do that by calling:

`rhumba::set_root_prefix(/path/to/prefix)`

Or use  micromamba shell init ... to initialize your shell, then restart. Check 
the use of micromamba [here](https://gist.github.com/wolfv/fe1ea521979973ab1d016d95a589dcde).

## Installation from source

### Requirements:

First make sure to have the following R packages:

- Rcpp
- Devtools

And the softwares:

- autoconf
- automake
- libtool

#### Windows, Mac and Linux:

Generate the `configure` file:

```
autoconf
```

Install packages:

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

## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the LICENSE file for details.