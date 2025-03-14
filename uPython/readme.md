# MicroPython MessagePack Experiments

`[micropython-msgpack](https://github.com/peterhinch/micropython-msgpack)` looks like a great starting place.

Making a **serialisable user class** that matches the (content) of `BluePad`'s universal gamepad data structure would be very nice.

For initial experiments, micropython on desktop might be good.

Easiest way is to use the pre-made official [Docker container](https://hub.docker.com/r/micropython/unix).

A [tutorial](https://bhave.sh/micropython-docker/).

Julian got it working just as easily using [podman](https://podman.io/) (uses docker for other things, this is a 'contained'-enough project to try `podman`.)
