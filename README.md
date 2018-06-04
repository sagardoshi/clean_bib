# clean_bib


## What clean_bib does

This project is a quite simple text processor to clean up some common problems for [ProQuest RefWorks](https://refworks.proquest.com/) BibTeX export files. It is only useful to anyone who uses ProQuest RefWorks as a citations manager for LaTeX. Personally, I use the convenience of [Overleaf](http://overleaf.com), and after processing my RefWorks export file, I simply load it straight into Overleaf.

For the moment, this only covers a number of idiosyncratic problems with the way that RefWorks exports its references into BibTeX. I would be very happy to add further features if there is any interest.

Features include:

  * Removing a user-inputted meta-field and its contents from all citations in which that meta-field occurs.
  * Adding spaces between citations for greater readability.
  * Removing any extraneous commas left at the end of the final key-value pair in a given citation that may have been left by the earlier removals.
  * Removing any extraneous whitespace between the key-value pairs and the `=` sign that divides them.
  * Adding `\` to escape special characters that cause trouble with BibTeX's `.bbl` files (currently only for `$` and `&`).

## How to use clean_bib

You will need to make use of the command line to use clean_bib. If this sounds unfamiliar, I would recommend exploring David Baumgold's neat and simple tutorial, [Getting to Know the Command Line](https://www.davidbaumgold.com/tutorials/command-line/).

After cloning or downloading the repository, navigate to the `clean_bib` directory using the command line. I assume you are already somewhat familiar with RefWorks. But if you are not, I recommend following [these instructions (PDF)](https://www.imperial.ac.uk/media/imperial-college/administration-and-support-services/library/public/New-RefWorks-with-LaTeX-sep-2017.pdf) to export your references into BibTeX format.

> **IMPORTANT** The whole point for this program is that RefWorks has a number of bugs. Most important among these is that the export function, in my experience, does **not** work at all in Google Chrome. I find it more stable on Mozilla Firefox (still not very clean, but good enough), and it will at least allow you to export your citations that way.

Once you export your references, RefWorks will automatically save them with the name ``export.bib``. Currently, my program requires your `.bib` file to be named precisely this way and to be located in its directory. So be sure your downloaded file has that name, and copy it into your new `clean_bib` directory.

Run the `make` command. Because this is a C++ program, we need to use the compiler to convert our program into object code and finally into a machine-executable format. Running that command will produce an executable file called, simply enough, `clean_bib`. Then, run `make run` to execute the program. From there, the instructions should direct you the rest of the way. The program will overwrite the export.bib file. So when complete, take a look at your file, make any adjustments, and place it into your LaTeX project.

> **NOTE** Currently, my program replaces the clunky RefWorks auto-generated keyword IDs in each citation with the simple index of the citation (starting with 1). Typical convention in BibTeX is to replace that keyword with `[author_surname][year]`, but it is up to you to further adjust the keyword as you wish. keep in mind that the program only changes the keyword for a citation that uses `RefWorks` in its keyword. If you use anything else, it will remain.

I typically run the program multiple times to remove any extraneous fields that I do not need in my references. Among other things, it is not easy in RefWorks to specify which fields you wish to export. This program will effectively allow you to filter out what you do not need.

---

I hope this is clear enough. This is not the most advanced program ever, but it should hopefully help you save some time, especially if you have a large number of references that regularly need updating. There is a good amount of work that could be put into improving this text processor, and if anyone is interested in contributing more, please feel free to fork this repository, perform some work, and notify me of any additional features you have added.

Thanks very much for trying this out!
