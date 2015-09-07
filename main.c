#include <stdio.h>
#include "highgui.h"
#include "cv.h"

int main() {

  char key;
  IplImage *image;
  CvCapture *capture;

  //capture = cvCreateFileCapture("/path/to/your/video/test.avi"); // chemin pour un fichier
  capture = cvCreateCameraCapture(CV_CAP_ANY);

  if (!capture) {

    printf("Ouverture du flux vidéo impossible !\n");
    return 1;

  }

  cvNamedWindow("GeckoGeek Window", CV_WINDOW_AUTOSIZE);

  while(key != 'q' && key != 'Q')
    {
      image = cvQueryFrame(capture);
      cvShowImage( "GeckoGeek Window", image);
      key = cvWaitKey(10);
    }
  cvReleaseCapture(&capture);
  cvDestroyWindow("GeckoGeek Window");
  return 0;
}
