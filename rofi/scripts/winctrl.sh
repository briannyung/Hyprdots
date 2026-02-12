#!/bin/bash

options="󰁍 Move\n󰁅 Resize\n󰁽 Toggle Float\n󰁙 Fullscreen\n󰁘 Kill"

choice=$(echo -e "$options" | rofi -dmenu -p "Window")

case "$choice" in
    *Move*) hyprctl dispatch movewindow ;;
    *Resize*) hyprctl dispatch resizewindow ;;
    *Float*) hyprctl dispatch togglefloating ;;
    *Fullscreen*) hyprctl dispatch fullscreen ;;
    *Kill*) hyprctl dispatch killactive ;;
esac
