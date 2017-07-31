glob-escape
###########

glob-escape is a small library because I quite stupidly didn't realise that the
``[`` and ``]`` characters in my folders I was trying to use glob in were also
being consumed by glob itself.

Usage
=====

.. code-block:: C

    #include <globescape.h>

    char string_to_escape[] = "/test/hello [1999]"
    char *escaped_string = globescape(string_to_escape);
    printf("%s", escaped_string);
    /* /test/hello \[1999\] */

    // DO SOMETHING WITH STRING

    free(escaped_string);

Install
=======

Please note this code is licensed under LGPLv3. This means there are
limitations on how you can use it and are certain requirements to publish any
modifications and/or provide the ability to replace this library in your
application (among other things). If you have any problems with that, please
chuck me an email and we can discuss(should be on my Github profile).

Copy + Paste
------------
You can copy+paste the ``globescape.c`` and ``globescape.h`` into your project
directory, add ``#include "globescape.h"`` where needed and compile using
standard GCC flags/options. Nothing special is needed. This will work fine:

.. code-block:: bash

    gcc -c -o globescape.o globescape.c

and you can link it in with your application after.

Compile Shared Libraries
------------------------

Run the standard:
.. code-block:: bash

    make

    # optional

    make install

Then feel free to link in using the usual methods. Include the header file in
your project: ``#include <globescape.h>``.

TODO
====
(roughly in order of importance)

* Write tests.

* Use PATH_MAX everywhere I can to put limits on loops etc.

* Take in optional string_lengths, similar to strlen and strnlen.

* Confirm that ``]`` is not being escaped correctly,
  - if not working, fix escaping ``]`` properly after ``[``.

* Write a function that will insert into string inplace so no need for extra
  malloc.

* Investigate more efficient algorithms (may need to ask external help for
  this part, I don't have much experience with algorithms generally).

* Investigate whether I should not escape if already escaped.

* Implement filtering out specific characters using flags
  - i.e. don't escape ``?`` if passing in ``NO_QUESTION_MARK`` flag

License
=======

LGPLv3
