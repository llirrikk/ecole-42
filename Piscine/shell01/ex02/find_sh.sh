#!/bin/sh
find . -name "*.sh" -type f -exec basename {} \; | rev | cut -c 4- | rev
