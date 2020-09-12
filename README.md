# extension-vibrate

Adds support for device vibration service in Defold.

# Platform support

The currently supported platforms are: iOS and Android


# FAQ

## How do I use this extension?

Add the package link (https://github.com/adamwestman/extension-vibrate/archive/master.zip)
to the project setting `project.dependencies`, and you should be good to go.

See the [manual](http://www.defold.com/manuals/libraries/) for further info.


# Usage

```lua
if vibrate then
  vibrate.trigger()
end
```
Invoke the device specific vibration service.

