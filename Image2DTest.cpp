#include "gmock/gmock.h"    
#include "Image2D.h"    
#include <cstdlib>

using namespace ::testing;

class Image2DTest : public ::testing::Test {

protected:

void SetUp() override {
   im.resize(16,16);
   imOnes.resize(16,16);
   imZeros.resize(16,16);
   
   for(int i=0 ; i < im.sizey(); i++) {
      for(int j=0 ; j < im.sizey(); j++) {
         im(i,j) = static_cast<float>(rand())/INT_MAX;
      }

   } 

   for(int i=0 ; i < imOnes.sizey(); i++) {
      for(int j=0 ; j < imOnes.sizey(); j++) {
         imOnes(i,j) = 1.0f;
      }
   } 

   for(int i=0 ; i < imOnes.sizey(); i++) {
      for(int j=0 ; j < imOnes.sizey(); j++) {
         imZeros(i,j) = 0.0f;
      }
   } 
}

void TearDown() override {

}

   Image2D im;
   Image2D imOnes;
   Image2D imZeros;
};

TEST_F(Image2DTest, testDefaultConstruction) {

   Image2D imZero;

   ASSERT_EQ(imZero.sizex(), 0);
   ASSERT_EQ(imZero.sizey(), 0);

}

TEST_F(Image2DTest, testConstructionWithArgs) {

   ASSERT_EQ(im.sizex(), 16);
   ASSERT_EQ(im.sizey(), 16);

}

TEST_F(Image2DTest, test2DIndexing) {


   im(1,1) = 15;

   ASSERT_EQ(im(1,1), im[im.sizex()+1]);

}

TEST_F(Image2DTest, testCheckSum) {

   ASSERT_EQ(imOnes.checkSum(), im.size());

}

TEST_F(Image2DTest, testSelfDiff) {

   imSub(imZeros, im, im);

   ASSERT_EQ(imZeros.checkSum(), 0);


}

TEST_F(Image2DTest, testStencil) {

   Image2D filter(3,3);

   filter(0,0) = -1;
   filter(0,1) =  0;
   filter(0,2) =  1;
   filter(1,0) = -1;
   filter(1,1) =  0;
   filter(1,2) =  1;
   filter(2,0) = -1;
   filter(2,1) =  0;
   filter(2,2) =  1;

   imFilter(imZeros, imOnes, filter);

   ASSERT_EQ(imZeros.checkSum(), 0);

}
