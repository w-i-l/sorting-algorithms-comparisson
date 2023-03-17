<h1>Sorting Algorithms</h1>
<h2>A brief comparisson</h2>
<img src='https://user-images.githubusercontent.com/65015373/225962648-f6c3e0f1-31b1-4a21-ae6d-4816eaca0150.png'>



<br>
<hr>
<h2>About it</h2>

<p>A project to determine the best usecase for 5 sorting algorithms based on different inputs.</p>

<p>The algorithm used are:</p>
<ul>
    <li>Merge sort</li>
    <li>Quick sort</li>
    <li>Radix sort</li>
    <li>Shell sort</li>
    <li>Count sort</li>
</ul>

<p>After performing some tests, all the data collected were put in graphs for an easier understanding. The presentation of the results can be found in <a href='https://github.com/w-i-l/data_structure_1_hw/tree/main/Presentation'>Presentation</a> folder.</p>

<br>
<hr>
<h2>How to use it</h2>

<p>The implementation for each algorithm can be found in <a href = 'https://github.com/w-i-l/data_structure_1_hw/tree/main/Sorting%20Algorithm'/>Sorting algorithm</a> folder.</p>
<p>The <code>main.cpp</code> file contains all the sorting algorithm implemented. In the <code>main</code> function is built a test for every algorithm that measure the execution time and writes it in a <code>.txt</code> file. </p>

<p>Compile the main file using:</p>
<code>g++ main.cpp -o main -O3</code>

<p>To run you have to pass 3 arguments that represents in order:</p>
<ol>
    <li>the maximum number - which describes the range (1...maximum_number)</li>
    <li>the number of elements of the array</li>
    <li>the base for radix sort</li>
</ol>
<p>The running command should pass all the argumets with a dash:</p>
<code>./main.exe -maximum_number -no_of_elements -base</code>

<p>The <code>main.py</code> file contains an automated tester for this program. You can perform any test you want by changing the parameters.</p>
<p>Just ensure you compiled the <code>.cpp</code> file first and then run this:</p>
<code>python3 main.py</code>

