#!/bin/zsh

rm -f /usr/include/minirt.h
cp -f include/minirt.h /usr/include
rm -f /usr/include/libft.h
cp libs/libft.h /usr/include
rm -f /usr/include/tester.h
cp tests/tester.h /usr/include
rm -f /usr/lib/minirt.a
test -f minirt.a && cp -f minirt.a /usr/lib/minirt.a
