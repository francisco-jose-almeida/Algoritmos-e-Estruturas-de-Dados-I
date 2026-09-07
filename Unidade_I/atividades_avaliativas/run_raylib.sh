#!/bin/bash

gcc $1 -o $2 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
