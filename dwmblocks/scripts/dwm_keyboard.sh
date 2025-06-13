#!/bin/sh
# выводит иконку и текущую раскладку (EN/RU)

layout=$(setxkbmap -query | awk '/layout/{print $2}')
if [ "$layout" = "us" ]; then
  code="EN"
else
  code="RU"
fi

printf " %s" "$code"