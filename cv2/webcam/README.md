# Read from Webcam
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

We want to capture the webcam via CV2.

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)

```shell
pip install opencv-contrib-python
```

```python
import numpy as np
import cv2

def record_video(
    camera_index: int,
    n_frames: int,
    fps: float = 20.0,
    framesize: tuple[int, int] = (640, 480),
    display: bool = False,
) -> tuple[bool, np.ndarray]:
    cap = cv2.VideoCapture(camera_index)
    assert cap.isOpened() is True, "record_video: Errror during opening the device!"

    cap.set(cv2.CAP_PROP_FPS, fps)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, framesize[0])
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, framesize[1])
    print(
        f"Capturing: {cap.get(cv2.CAP_PROP_FRAME_WIDTH):.0f} x {cap.get(cv2.CAP_PROP_FRAME_HEIGHT):.0f} @ {cap.get(cv2.CAP_PROP_FPS):.1f}."
    )

    for i_frame in range(n_frames):
        success, frame = cap.read()
        assert success is True, "record_video: Some error during capturing occurred!"

        if i_frame == 0:
            frames = np.zeros((*frame.shape, n_frames)).astype(np.uint8)
        frames[:, :, :, i_frame] = frame
        if display is True:
            cv2.imshow("Capture", frame)
            retval = cv2.waitKey(1)
            if retval != -1:
                frames = frames[:, :, :, 0 : i_frame + 1]
                break
    cap.release()
    if display is True:
        cv2.destroyWindow("Capture")
    return success, frames


if __name__ == "__main__":
    success, frames = record_video(
        camera_index=0,
        n_frames=200,
        fps=20.0,
        framesize=(640, 480),
        display=True,
    )

    print(success) # -> True
    print(frames.shape) # -> (480, 640, 3, 200)
```
