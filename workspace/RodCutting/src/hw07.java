import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class hw07 {




 private static int minimum(int a, int b, int c) {

  return Math.min(Math.min(a, b), c);
 }

 public static int computeLevenshteinDistance(CharSequence lhs, CharSequence rhs, int ins, int del, int swap, List < String > resultOperations) {
  int[][] distance = new int[lhs.length() + 1][rhs.length() + 1];

  for (int i = 0; i <= lhs.length(); i++)
   distance[i][0] = i;
  for (int j = 1; j <= rhs.length(); j++)
   distance[0][j] = j;

  for (int i = 1; i <= lhs.length(); i++)
   for (int j = 1; j <= rhs.length(); j++) {

    int insert = distance[i][j - 1] + ins;
    int delete = distance[i - 1][j] + del;

    //if the characters are the same, a replacement has no cost
    int replace = distance[i - 1][j - 1] + ((lhs.charAt(i - 1) == rhs.charAt(j - 1)) ? 0 : swap);

    distance[i][j] = minimum(
     delete,
     insert,
     replace);
    if (i == j || (i == lhs.length() && j > i)) {
     if (distance[i][j] == insert) {

      resultOperations.add("insert " + rhs.charAt(j - 1));
     } else if (distance[i][j] == delete) {

      resultOperations.add("delete " + lhs.charAt(i - 1));
     } else {
      resultOperations.add("replace " + lhs.charAt(i - 1) + " with " + rhs.charAt(j - 1));
     }


    }

   }



  return distance[lhs.length()][rhs.length()];
 }


 public static void main(String args[]) {



  List < Double > p = Arrays.asList(1.0, 5.0, 8.0, 9.0, 10.0, 17.0, 18.0, 20.0, 24.0, 30.0);

  List < String > a = new ArrayList();
  List < String > b = new ArrayList();
  Rod staff = new Rod(p);
  System.out.println(staff.p);

  //System.out.println(staff.rodCut1(1, staff.p, staff.solutions));
  //	System.out.println(staff.rodCut2(1, staff.p, staff.solutions));
  //System.out.println(staff.rodCut3(1, staff.p, staff.solutions));





  System.out.println(staff.rodCut1(10, staff.p, staff.solutions));
  System.out.println(staff.solutions);
  for (int i = 0; i < staff.solutions.size(); i++) {
   staff.solutions.set(i, i - staff.solutions.get(i));
  }
  System.out.println(staff.solutions);

  System.out.println(staff.rodCut2(10, staff.p, staff.solutions));
  System.out.println(staff.solutions);
  for (int i = 0; i < staff.solutions.size(); i++) {
   staff.solutions.set(i, i - staff.solutions.get(i));
  }
  System.out.println(staff.solutions);

  System.out.println(staff.rodCut3(10, staff.p, staff.solutions));
  System.out.println(staff.solutions);
  for (int i = 0; i < staff.solutions.size(); i++) {
   staff.solutions.set(i, i - staff.solutions.get(i));
  }
  System.out.println(staff.solutions);
  //identical results to the example in the book for all three methods


  //System.out.println(staff.solutions.);
  String s = "kitten";
  String t = "sitting";

  System.out.println(computeLevenshteinDistance(s, t, 1, 1, 1, a));
  System.out.println(a);

  /*
  System.out.println(computeLevenshteinDistance(s,t,2,1,1,a));
  System.out.println(computeLevenshteinDistance(s,t,2,2,2,a));
  System.out.println(computeLevenshteinDistance(s,t,3,3,3,a));
  System.out.println(computeLevenshteinDistance(s,t,1,1,3,a));
  */
 }

}





class Rod {

 List < Double > p = new ArrayList();
 List < Integer > solutions = new ArrayList < Integer > ();

 public Rod(List < Double > x) {
  this.p = x;
  for (int i = 0; i <= x.size(); i++) {
   this.solutions.add(0);
  }
 }

 public static double rodCut3(int length, List < Double > prices, List < Integer > resultCuts) {
  //List<Double> r = new ArrayList<Double>();


  double[] r = new double[length + 1];
  double[] s = new double[length + 1];
  r[0] = 0;
  double q = 0.0;
  if (length == 0)
   return 0;
  if (length == 1)
   return prices.get(0);


  for (int j = 0; j < r.length; j++) {

   q = 0.0;

   for (int i = 0; i < j; i++) {

    double price = Double.NEGATIVE_INFINITY;

    price = prices.get(i);
    if (q < price + r[j - i - 1]) {


     q = price + r[j - i - 1];
     //	s[j] = i;

     resultCuts.set(j, (i + 1));

    }

   }

   r[j] = q;

  }


  return r[length];
 }


 public double rodCut2(int length, List < Double > prices, List < Integer > resultCuts) {



  List < Double > r = new ArrayList < Double > ();
  r.add(Double.NEGATIVE_INFINITY);
  for (int i = 0; i < length; i++)
   r.add(Double.NEGATIVE_INFINITY);

  return rcHelper(length, prices, r, resultCuts);
 }

 double rcHelper(int length, List < Double > prices, List < Double > r, List < Integer > resultCuts) {

  double q = Double.NEGATIVE_INFINITY;
  if (length > 0) {

   if (r.get(length - 1) >= 0) {

    return r.get(length);

   }
  }

  if (length == 0)
   q = 0;
  for (int i = 0; i < length; i++) {

   double compare = prices.get(i) + rcHelper(length - i - 1, prices, r, resultCuts);
   double qlast = q;
   q = Math.max(q, compare);
   if (q > qlast)
    resultCuts.set(length, i + 1);


   //	if(prices.contains(q))

  }

  r.set(length, q);
  //System.out.println(r);
  return q;
 }


 public double rodCut1(int length, List < Double > prices, List < Integer > resultCuts) {

  if (length == 0) {
   return 0;

  }

  double q = Double.NEGATIVE_INFINITY;

  for (int i = 0; i < length; i++) {
   double qlast = q;
   q = Math.max(q, prices.get(i) + rodCut1(length - i - 1, prices, resultCuts));
   if (qlast != q)
    resultCuts.set(length, i + 1);
  }



  return q;
 }

}