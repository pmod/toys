#!/bin/sh

dbus-send --system --print-reply --dest=org.freedesktop.NetworkManager /org/freedesktop/NetworkManager/Devices/0 org.freedesktop.DBus.Properties.Get string:org.freedesktop.NetworkManager.Device string:StateReason
