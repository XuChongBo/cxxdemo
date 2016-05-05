import ocr
import sys
model_dir =  "/home/xucb/projects/OCR/tw_ocr/models"

import os.path
import cv2
import requests
from urlparse import urlparse
import cStringIO
import PIL.Image
import numpy as np

def is_url(url):
    return url is not None and urlparse(url).scheme != "" and not os.path.exists(url)

def get_cvmat(path):    
    if is_url(path):
            r = requests.get(path,
                    allow_redirects=False,
                    timeout=2)
            r.raise_for_status()
            stream = cStringIO.StringIO(r.content)
            image = PIL.Image.open(stream)
    else:
        image = PIL.Image.open(path)
    imgcv = np.asarray(image.convert('L'))
    return imgcv

if __name__ == '__main__':
    if len(sys.argv)>=2:
        path = sys.argv[1]
        imgcv = get_cvmat(path)
        result = ocr.recognize_by_cvmat(imgcv, model_dir)
        print result
        cv2.imshow("x", imgcv)
        cv2.waitKey(0)
    else:

        filename = "/home/xucb/data/ocr_test_set/test_math.png"

        result = ocr.recognize_by_image_path(filename, model_dir)
        print result


        import cv2
        img = cv2.imread(filename)
        print ocr.recognize_by_cvmat(img, model_dir)

        answer_imagefile = "/home/xucb/data/tiku_answers/sample_png/00D536C4-4265-11E5-AD7E-525400FBBE7B.png"
        print ocr.recognize_tiku_answer_by_image_path(answer_imagefile, model_dir)

        import ocr
        #mapcontainer = ocr.pySImap()
        mapcontainer = ocr.a()
        print mapcontainer
        for i in mapcontainer:
            print i

        d = {}
        for i in mapcontainer:
            key = i.key()
            d[key] = i.data()
        print d
        print img.shape
        st = ocr.MyStruct()
        # st.a = 44
        # st.msg = "abc"
        # st.img = img
        st = ocr.get_image(filename)
        #print dir(st.img)
        #a = np.array(st.img)
        #print a.shape
        print st.a
        print st.msg
        cv2.imshow("x",st.img)
        cv2.waitKey(0)
