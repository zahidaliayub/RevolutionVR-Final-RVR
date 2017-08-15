<a href="http://i.imgur.com/E8ESrsq.png"><img src="http://i.imgur.com/E8ESrsq.png" title="" /></a>


VOXELS (VOX)
===========

www.voxelus.com/

What is Voxels?
----------------

Voxels is an experimental in game digital currency created for Voxelus users. 
Voxels allows for instant payments to anyone, anywhere in the world. 
Voxels was built on Litcoin core with modifications.
Voxels uses peer-to-peer technology to operate with no central authority.
Managing transactions and issuing money are carried
out collectively by the network. Voxels Core is the name of the source
software which enables the use of this currency.

For more information about Voxelus, visit www.voxelus.com/

Specs
-----
POW Scrypt Cryptocurrency

210,000,000 Premined Coins  

0 Block Reward

2.5 Minute Blocks (On Average)

60 Block Retarget Rate

RPC Port 9537

P2P Port 9538


License
-------

Voxels Core is released under the terms of the MIT license.
See http://opensource.org/licenses/MIT/ for more information.

Development process
-------------------

Futher Developers work is handled by Michael Wheeler, Martin Repetto & Jonathan Heald longside the Voxelus Team, Email community@voxelus.com

If it is a simple/trivial/non-controversial change, then one of the Voxels
development team members simply pulls it.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. 

Testing
-------

Testing and code review is handled by Blaskoshi and Voxels Team.


Translations
------------

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translations may be converted to Voxels periodically.

Development tips and tricks
---------------------------

**compiling for debugging**

Run configure with the --enable-debug option, then make. Or run configure with
CXXFLAGS="-g -ggdb -O0" or whatever debug flags you need.

**debug.log**

If the code is behaving strangely, take a look in the debug.log file in the data directory;
error and debugging messages are written there.

The -debug=... command-line option controls debugging; running with just -debug will turn
on all categories (and give you a very large debug.log file).

The Qt code routes qDebug() output to debug.log under category "qt": run with -debug=qt
to see it.


**DEBUG_LOCKORDER**

Voxels Core is a multithreaded application, and deadlocks or other multithreading bugs
can be very difficult to track down. Compiling with -DDEBUG_LOCKORDER (configure
CXXFLAGS="-DDEBUG_LOCKORDER -g") inserts run-time checks to keep track of which locks
are held, and adds warnings to the debug.log file if inconsistencies are detected.
