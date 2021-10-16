/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/*
// Students may decide to take different "tracks" or sequences of courses in the Computer Science curriculum.
//There may be more than one track that includes the same course, but each student follows a single linear track
//from a "root" node to a "leaf" node. In the graph below, their path always moves left to right.
// Write a function that takes a list of (source, destination) pairs, and returns the name of all 
//of the courses that the students could be taking when they are halfway through their track of courses.
// Sample input:
// all_courses = [
//     ["Logic", "COBOL"],
//     ["Data Structures", "Algorithms"],
//     ["Creative Writing", "Data Structures"],
//     ["Algorithms", "COBOL"],
//     ["Intro to Computer Science", "Data Structures"],
//     ["Logic", "Compilers"],
//     ["Data Structures", "Logic"],
//     ["Creative Writing", "System Administration"],
//     ["Databases", "System Administration"],
//     ["Creative Writing", "Databases"],
// ]
// Sample output (in any order):
//      ["Creative Writing", "Databases", "Data Structures"]
// Visual representation:
//                                           ______________
// ____________                              |            |
// |          |        ______________     -->| Algorithms |--\     _____________
// | Intro to |        |            |    /   |____________|   \    |           |
// | C.S.     |---\    | Data       |   /                      >-->| COBOL     |
// |__________|    \   | Structures |--+     ______________   /    |___________|
//                  >->|____________|   \    |            |  /
// ____________    /                     \-->| Logic      |-+      _____________
// |          |   /    ______________        |____________|  \     |           |
// | Creative |  /     |            |                         \--->| Compilers |
// | Writing  |-+----->| Databases  |                              |___________|
// |__________|  \     |____________|-\     _________________________
//                \                    \    |                       |
//                 \--------------------+-->| System Administration |
//                                          |_______________________|
*/
void
launch (string & s, unordered_map < string, vector < string >> &items,
	vector < string > &temp, unordered_set < string > &endSet,
	vector < vector < string >> &paths)
{

  if (endSet.count (s))
    {
      temp.push_back (s);
      paths.push_back (temp);
      temp.pop_back ();
      return;
    }

  temp.push_back (s);

for (auto & ss:items[s])
    {
      launch (ss, items, temp, endSet, paths);
    }

  temp.pop_back ();
}


unordered_set < string > FindSetOfPrereqs (vector < vector < string >> &in)
{
  //start at each end point, find all possible paths back to start point
  //
  vector < vector < string >> paths;
  unordered_set < string > res;
  set < string > startPoints;
  set < string > endPoints;

  std::unordered_map < string, vector < string >> itemToLinks;

  for (int i = 0; i < in.size (); ++i)
    {
      startPoints.insert (in[i][0]);
      endPoints.insert (in[i][1]);
      itemToLinks[in[i][0]].push_back (in[i][1]);
    }

  vector < string > diffs;
  auto it = set_difference (startPoints.begin (), startPoints.end (),
			    endPoints.begin (), endPoints.end (),
			    back_inserter (diffs));
  unordered_set < string > startSet (diffs.begin (), diffs.end ());

  diffs.clear ();
  it = set_difference (endPoints.begin (), endPoints.end (),
		       startPoints.begin (), startPoints.end (),
		       back_inserter (diffs));
  unordered_set < string > endSet (diffs.begin (), diffs.end ());

for (std::string myStr:startSet)
    {

      vector < string > temp;
      vector < string > finalPath;
      launch (myStr, itemToLinks, temp, endSet, paths);
    }


for (const auto & v:paths)
    {
      int si = v.size ();
      if (si == 0)
	{
	  continue;
	}
      int finalVal = si / 2;
      if (si % 2 == 0)
	{
	  --finalVal;
	}
      res.insert (v[finalVal]);
    }

  return res;
}


int
main ()
{
  /*
     std::vector<int> t{1,2,3,3};
     std::vector<int> tt{3,4,5,6};
     std::vector<int> ttt{50,10,40,70};
     /*
     [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]

     jobScheduling(t, tt, ttt);
   */

  //std::string ss = "QQQQQQQQ";
//      int s = balancedString(ss);

  std::vector < std::vector < std::string >> in =
  {
    {
    "Logic", "COBOL"},
    {
    "Data Structures", "Algorithms"},
    {
    "Creative Writing", "Data Structures"},
    {
    "Algorithms", "COBOL"},
    {
    "Intro to Computer Science", "Data Structures"},
    {
    "Logic", "Compilers"},
    {
    "Data Structures", "Logic"},
    {
    "Creative Writing", "System Administration"},
    {
    "Databases", "System Administration"},
    {
  "Creative Writing", "Databases"},};

  auto thoue = FindSetOfPrereqs (in);

  return 0;
}
