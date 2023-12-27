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

## Read the data from a mp4 file

```python
import numpy as np
import cv2  # type: ignore


def read_video(filename: str, display: bool = False) -> np.ndarray:
    assert len(filename) > 0, "read_video: Filename is empty."

    frames: np.ndarray = np.array([])

    cap = cv2.VideoCapture(filename)

    assert cap.isOpened() is True, "read_video: Error opening video stream or file!"

    n: int = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
    x: int = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    y: int = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    print(f"Reading {n} frames with {x} x {y} pixels.")

    frames = np.zeros((y, x, 3, n)).astype(np.uint8)

    i: int = 0

    while cap.isOpened():
        ret, frame = cap.read()

        if ret is True:
            frames[:, :, :, i] = frame
            i += 1

            if display is True:
                cv2.imshow("Reading", frame)
                cv2.waitKey(25)
        else:
            break

    cap.release()

    if display is True:
        cv2.destroyWindow("Reading")

    return frames


movie = read_video("test.mp4", display=True)

print(movie.shape) # -> (100, 100, 3, 101)
```

## Playback a video

```python
import numpy as np
import cv2  # type: ignore
import time


def show_video(frames: np.ndarray, fps: float = 20.0) -> np.ndarray:
    assert frames.size > 0, "The frame is empty."
    assert frames.ndim == 4, "The frame has wrong dimensions."

    n: int = frames.shape[3]
    dt: float = 1 / fps

    t: np.ndarray = np.zeros((n + 1))

    t[0] = time.perf_counter()

    for i in range(n):
        frame = frames[:, :, :, i]
        cv2.imshow("Display", frame)
        t_wait: float = t[i] + dt - time.perf_counter()
        retval = cv2.waitKey(int(max(1, 1000 * t_wait)))
        t[i + 1] = time.perf_counter()
        if retval != -1:
            break
    cv2.destroyWindow("Display")

    return t


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

timings = show_video(frames=test_data, fps=20.0)
print(timings.shape) # -> (102,)
```
