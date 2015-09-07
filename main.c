/*
** main.c for  in /home/jobertomeu/Work/magicwall
**
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
**
** Started on  Mon Sep  7 14:53:35 2015 Joris Bertomeu
** Last update Mon Sep  7 14:53:36 2015 Joris Bertomeu
*/

#include	<stdio.h>
#include	"highgui.h"
#include	"cv.h"

int		main()
{
  char		key;
  IplImage	*image;
  CvCapture	*capture;

  //capture = cvCreateFileCapture("/path/to/your/video/test.avi");
  capture = cvCreateCameraCapture(CV_CAP_ANY);
  if (!capture)
    {
      printf("Ouverture du flux vidéo impossible !\n");
      return 1;
  }
  cvNamedWindow("MagicWall", CV_WINDOW_AUTOSIZE);
  while(key != 'q' && key != 'Q')
    {
      image = cvQueryFrame(capture);
      cvShowImage( "MagicWall", image);
      key = cvWaitKey(10);
    }
  cvReleaseCapture(&capture);
  cvDestroyWindow("MagicWall");
  return 0;
}
