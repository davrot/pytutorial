# OpenCV2: Play, write, read a video
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

How to playback a video? Howto save it into a mp4 file? Howto load from a mp4 file?

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

## Write the video into a mp4 file

```python

import numpy as np
import cv2  # type: ignore
import tqdm  # type: ignore


def write_video(frames: np.ndarray, filename: str = "test", fps: float = 20.0) -> None:
    assert len(filename) > 0, "write_video: Filename is empty."
    assert frames.size > 0, "write_video: The frame is empty."
    assert frames.ndim == 4, "write_video: The frame has wrong dimensions."

    x: int = frames.shape[1]
    y: int = frames.shape[0]
    n: int = frames.shape[3]
    fullname: str = filename + ".mp4"

    fourcc = cv2.VideoWriter_fourcc("m", "p", "4", "v")
    out = cv2.VideoWriter(fullname, fourcc, fps, (x, y))
    assert (
        out.isOpened() is True
    ), "write_video: Unknown error occurred during writing, closing file!"

    print(f"Writing frames into {fullname} at {fps:.1f} FPS.")

    for i in tqdm.trange(n):
        out.write(frames[..., i])

    out.release()


# Create test data
axis_x = np.arange(-50, 51)[:, np.newaxis, np.newaxis] / 50
axis_y = np.arange(-50, 51)[np.newaxis, :, np.newaxis] / 50
axis_z = np.arange(-50, 51)[np.newaxis, np.newaxis, :] / 50

test_data = np.sqrt(axis_x**2 + axis_y**2 + axis_z**2) < 0.75


# Adding an additional axis for the color channel
test_data = test_data[:, :, :, np.newaxis]
test_data = np.tile(test_data, (1, 1, 1, 3))
test_data = test_data.astype(dtype=np.float32)

# Put the time axis as last axis
test_data = np.moveaxis(test_data, 0, -1)


# Conversion to uint8
test_data -= test_data.min()
test_data /= test_data.max()
test_data *= 255
test_data = test_data.astype(dtype=np.uint8)


print(test_data.shape)  # -> (101, 101, 3, 101)

write_video(frames=test_data, filename="test", fps=20.0)
```


