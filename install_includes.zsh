#!/bin/zsh

rm -f /usr/include/minirt.h
cp include/minirt.h /usr/include
rm -f /usr/include/libft.h
cp libs/libft.h /usr/include
rm -f /usr/include/tester.h
cp tests/tester.h /usr/include
rm -f /usr/lib/minirt.a
cp minirt.a /usr/lib/minirt.a
