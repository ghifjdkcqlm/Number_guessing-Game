import cv2
import numpy as np
import time

cap = cv2.VideoCapture(0)
time.sleep(2)
background = None

for i in range(30):
    ret, background = cap.read()

background = cv2.flip(background, 1)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
    frame = cv2.flip(frame, 1)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_green = np.array([35, 50, 50])
    upper_green = np.array([85, 255, 255])
    mask = cv2.inRange(hsv, lower_green, upper_green)

    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, np.ones((3, 3), np.uint8))
    mask = cv2.morphologyEx(mask, cv2.MORPH_DILATE, np.ones((3, 3), np.uint8))

    inverse_mask = cv2.bitwise_not(mask)

    res1 = cv2.bitwise_and(background, background, mask=mask)
    res2 = cv2.bitwise_and(frame, frame, mask=inverse_mask)

    final_output = cv2.addWeighted(res1, 1, res2, 1, 0)

    cv2.imshow("Invisibility Cloak", final_output)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
