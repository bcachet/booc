Project created to improve my skills with C language.

There are few approach or even frameworks that let you write Object Oriented code in Standard C language (C99).

I want to have a TDD approach using the Ceedling project which embed Unity testing framework, OCMock, CException.

Here is a list of the approach I want to test:
 * `Object Oriented Programming in C Approaches`_
 * `OOC Programming language`_
 * `Object Oriented Programming in C`_ 



.. _OOC Programming language: http://ooc-lang.org/
.. _Object Oriented Programming in C: http://www.cs.rit.edu/~ats/books/ooc.pdf
.. _Object Oriented Programming in C Approaches: http://home.comcast.net/~fbui/OOC.html



Sublime Text 2
______________

I use sublime text for this development. I have developed a new Build System that contains the following:

	{
		"cmd": ["rake", "test:all"],
		"working_dir": "${project_path:${folder}}/"
	}
	
These task launch all the tests that are located in the _test_ directory using the rakefile.rb file provided by Ceedling.
You just have to specify in the project.yml what is the test_file_prefix. In our case it is test_.

After you have selected the Build System to use in Tools > Build System, you just have to hit Cmd + B to launch the unit tests and see the result.
