# !/bin/env/bash bash
cat test.html | ./tagMain | diff - removed.html


