/*
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.@wwyqianqian
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;






//Milestone 1: Greatest Common Denominator
// 第一题，最大公约数，辗转相除法。
//(24,7)->(7,3)->(3,1)->(1,0) b == 0 -> a = 1; endl
int gcd(int a, int b) {
    if ( b == 0 ){
      cout << "gcd(" << a << "," << b << ") = " << a << endl;
      return a;
    }
    else{
       cout << "gcd(" << a << "," << b << ") = " << "gcd(" << b << "," << a%b << ")" << endl;
       return gcd( b, a%b );
    }
    return 0;
}






//Milestone 2: Serpinskii Fractal
//第二题，画三角形，左上角点作为大基点，计算size（边长）和高度，重复画三角形，可以重复描边。
void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    if (order == 1){
        w.drawLine (leftX, leftY, size + leftX, leftY);  //左上，右上连线函数。
        w.drawLine (size + leftX, leftY, size / 2.0 + leftX, size * sqrt( 3 ) / 2.0 + leftY);  //右上，下连线函数
        w.drawLine (size / 2.0 + leftX, size * sqrt( 3 ) / 2.0 + leftY, leftX, leftY);  //下，左上连线函数。
    }
    if (order == 0){
        return;
    }
    if (order < 0){
        throw ("error!");
        return;
    }
    else{
        serpinskii(w, leftX, leftY, size / 2.0, order - 1);  //以左上点为基点，相对父元素为 1/4 的小三角形。两条边重复。
        serpinskii(w, leftX + size / 2.0, leftY, size / 2.0, order - 1); //以上线中点为基点
        serpinskii(w, leftX + size / 4.0, leftY + height/ 2.0, size / 2.0, order - 1);  //以左线中点为基点
    }
}






//Milestone 3: Flood Fill
//第三题，填充颜色。分别检查，改变上下左右像素的RGB。
//image.getRGB(x, y);        	          返回像素颜色
//image.setRGB(x, y, color);	          给像素上色
//image.getWidth(); image.getHeight();  返回图形的宽高 单位px
//image.inBounds(x, y);	                pixel (x, y)在界内，返回TRUE
int floodFill(GBufferedImage& image, int x, int y, int newColor) {
   oldColor = image.getRGB(x, y);
   if(oldColor != newColor){
        return fillColor(image, x, y, newColor, oldColor);
   }
   return 0;
}

int fillColor(GBufferedImage& image, int x, int y, int newColor, int oldColor) {
    int count;

    if(image.inBounds(x, y) && oldColor == image.getRGB(x, y)){
        image.setRGB(x, y, newColor);
        count++;
        fillColor(image, x-1, y, newColor, oldColor);
        fillColor(image, x+1, y, newColor, oldColor);
        fillColor(image, x, y+1, newColor, oldColor);
        fillColor(image, x, y-1, newColor, oldColor);
}
    return count;
}






//Milestone 4: Personalized Curriculum
//第四题，找出他所包含的私有课程，直到打印出自己personalCurriculum。
void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal){

    Set <string> alreadymentioned;
    alreadymentioned.add(goal);
    betterCurriculum(prereqMap, goal, alreadymentioned);
    cout << goal << endl;

}
void betterCurriculum(Map<string, Vector<string>> & prereqMap, string goal, Set<string> & alreadymentioned){

    if (prereqMap.get(goal).isEmpty()){
        return;
    }
    else{
       for (string classname: prereqMap.get( goal )){
           betterCurriculum(prereqMap , classname , alreadymentioned);
           if(!alreadymentioned.contains( classname )){
              cout << classname << endl;
            }
           alreadymentioned.add(classname);
       }
    }
}






//Milestone 5: Generate Question
//第五题，组个句子？？？（（不是很懂
string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
