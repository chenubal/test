/* 
 * File:   ImProcEBC.h
 * Author: josef
 *
 * Created on 3. April 2013, 17:00
 */

#ifndef IMPROCEBC_H
#define	IMPROCEBC_H

#include "BasicEBC.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class Loader : public Isomorph< std::string const&, cv::Mat>
{
public:

   virtual void process(std::string const& filename)
   {
      out(cv::imread(filename, 1));
   }
};

class Writer : public Terminal< cv::Mat>
{
   std::string filename;
public:

   Writer(std::string const& fname) : filename(fname)
   {
   }

   virtual void process(cv::Mat const& m)
   {
      std::cout << "write " << filename <<std::endl;
      cv::imwrite(filename, m);
   }
};

#endif	/* IMPROCEBC_H */

