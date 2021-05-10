// Copyright (c) 2020, QuantStack and Mamba Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#include <Rcpp.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

#include <csignal>

#include "mamba/api/c_api.h"


namespace r = Rcpp;

// [[Rcpp::plugins(cpp17)]]

void set_config(const char* name, const std::vector<std::string>& values)
{
    std::vector<std::string> separated_values;
    for(auto& v: values)
    {
        separated_values.push_back(v);
        if (v != *(values.end() - 1))
            separated_values.push_back(",");
    }

    std::string value = std::accumulate(separated_values.begin(), separated_values.end(), std::string(""));
    mamba_set_config(name, value.data());
}

void set_specs(const std::vector<std::string>& specs)
{
    set_config("specs", specs);
}

// [[Rcpp::export]]
void set_channels(const std::vector<std::string>& channels)
{
    set_config("channels", channels);
}

// [[Rcpp::export]]
void set_config(const char* name, const char* value)
{
    mamba_set_config(name, value);
}

// [[Rcpp::export]]
void clear_config(const char* name)
{
    mamba_clear_config(name);
}

void set_prefix(const char* prefix)
{
    std::string prefix_str = prefix;

    if (!prefix_str.empty())
    {
        if (prefix_str.find_first_of("/\\") == std::string::npos)
        {
            mamba_set_cli_config("env_name", prefix);
        }
        else
        {
            mamba_set_cli_config("target_prefix", prefix);
        }
    }
}

void hide_banner()
{
    mamba_set_config("show_banner", "false");
}

// [[Rcpp::export]]
void print_config()
{
    mamba_config_list();
}

// [[Rcpp::export]]
void list(const char* regex = "", const char* prefix = "")
{
    set_prefix(prefix);
    mamba_list(regex);
}

// [[Rcpp::export]]
void create(const std::vector<std::string>& specs, const char* prefix)
{
    hide_banner();
    set_specs(specs);
    set_prefix(prefix);
    mamba_create();
}

// [[Rcpp::export]]
void install(const std::vector<std::string>& specs, const char* prefix = "")
{
    hide_banner();
    set_specs(specs);
    set_prefix(prefix);
    mamba_install();
}

// [[Rcpp::export]]
void update(const std::vector<std::string>& specs, int update_all = 0, const char* prefix = "")
{
    hide_banner();
    set_specs(specs);
    set_prefix(prefix);
    mamba_update(update_all);
}

// [[Rcpp::export]]
void remove(const std::vector<std::string>& specs, int remove_all = 0, const char* prefix = "")
{
    hide_banner();
    set_specs(specs);
    set_prefix(prefix);
    mamba_remove(remove_all);
}

// [[Rcpp::export]]
void info(const char* prefix = "")
{
    set_prefix(prefix);
    mamba_info();
}
