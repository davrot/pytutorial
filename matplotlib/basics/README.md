# Basics of matplotlib.pyplot
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal



Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


> **pylab** is a historic interface and **its use is strongly discouraged**. The equivalent replacement is matplotlib.pyplot

## [Managing Figure and Axes](https://matplotlib.org/stable/api/pyplot_summary.html#managing-figure-and-axes)

|||
|---|---|
|[axes](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.axes.html#matplotlib.pyplot.axes)|Add an Axes to the current figure and make it the current Axes.|
|[cla](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.cla.html#matplotlib.pyplot.cla)|Clear the current axes.|
|[clf](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.clf.html#matplotlib.pyplot.clf)|Clear the current figure.|
|[close](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.close.html#matplotlib.pyplot.close)|Close a figure window.|
|[delaxes](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.delaxes.html#matplotlib.pyplot.delaxes)|Remove an Axes (defaulting to the current axes) from its figure.|
|[fignum_exists](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.fignum_exists.html#matplotlib.pyplot.fignum_exists)|Return whether the figure with the given id exists.|
|[figure](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.figure.html#matplotlib.pyplot.figure)|Create a new figure, or activate an existing figure.|
|[gca](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.gca.html#matplotlib.pyplot.gca)|Get the current Axes.|
|[gcf](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.gcf.html#matplotlib.pyplot.gcf)|Get the current figure.|
|[get_figlabels](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.get_figlabels.html#matplotlib.pyplot.get_figlabels)|Return a list of existing figure labels.|
|[get_fignums](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.get_fignums.html#matplotlib.pyplot.get_fignums)|Return a list of existing figure numbers.|
|[sca](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.sca.html#matplotlib.pyplot.sca)|Set the current Axes to ax and the current Figure to the parent of ax.|
|[subplot](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot.html#matplotlib.pyplot.subplot)|Add an Axes to the current figure or retrieve an existing Axes.|
|[subplot2grid](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot2grid.html#matplotlib.pyplot.subplot2grid)|Create a subplot at a specific location inside a regular grid.|
|[subplot_mosaic](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplot_mosaic.html#matplotlib.pyplot.subplot_mosaic)|Build a layout of Axes based on ASCII art or nested lists.|
|[subplots](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplots.html#matplotlib.pyplot.subplots)|Create a figure and a set of subplots.|
|[twinx](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.twinx.html#matplotlib.pyplot.twinx)| Make and return a second axes that shares the x-axis.|
|[twiny](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.twiny.html#matplotlib.pyplot.twiny)| Make and return a second axes that shares the y-axis.|

## [Basic](https://matplotlib.org/stable/api/pyplot_summary.html#basic)

more [Basic](https://matplotlib.org/stable/api/pyplot_summary.html#basic)

|||
|---|---|
|[plot]()|Plot y versus x as lines and/or markers.|
|[errorbar]()|Plot y versus x as lines and/or markers with attached errorbars.|
|[scatter]()|A scatter plot of y vs.|
|[step]()|Make a step plot.|
|[loglog]()|Make a plot with log scaling on both the x- and y-axis.|
|[semilogx]()|Make a plot with log scaling on the x-axis.|
|[semilogy]()|Make a plot with log scaling on the y-axis.|
|[bar]()|Make a bar plot.|
|[barh]()|Make a horizontal bar plot.|
|[bar_label]()|Label a bar plot.|
|[pie]()|Plot a pie chart.|
|[vlines]()|Plot vertical lines at each x from ymin to ymax.|
|[hlines]()|Plot horizontal lines at each y from xmin to xmax.|
|[fill]()|Plot filled polygons.|
|[polar]()|Make a polar plot.|

## [Spans](https://matplotlib.org/stable/api/pyplot_summary.html#spans)
[Spans](https://matplotlib.org/stable/api/pyplot_summary.html#spans)


## [Spectral](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)
[Spectral](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

## [Binned](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

more [Binned](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

|||
|---|---|
|[hist]()|Compute and plot a histogram.|
|[hist2d]()|Make a 2D histogram plot.|

## [Contours](https://matplotlib.org/stable/api/pyplot_summary.html#contours)

|||
|---|---|
|[clabel]()|Label a contour plot.|
|[contour]()|Plot contour lines.|
|[contourf]()|Plot filled contours.|

## [2D arrays](https://matplotlib.org/stable/api/pyplot_summary.html#d-arrays)

more [2D arrays](https://matplotlib.org/stable/api/pyplot_summary.html#d-arrays)

|||
|---|---|
|[imshow]()|Display data as an image, i.e., on a 2D regular raster.|

## [Unstructured triangles](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)
[Unstructured triangles](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)

## [Text and annotations](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)

|||
|---|---|
|[annotate]()|Annotate the point xy with text text.|
|[text]()|Add text to the Axes.|
|[figtext]()|Add text to figure.|
|[table]()|Add a table to an Axes.|
|[arrow]()|Add an arrow to the Axes.|
|[figlegend]()|Place a legend on the figure.|
|[legend]()|Place a legend on the Axes.|

## [Vector fields](https://matplotlib.org/stable/api/pyplot_summary.html#vector-fields)
[Vector fields](https://matplotlib.org/stable/api/pyplot_summary.html#vector-fields)

## [Axis configuration](https://matplotlib.org/stable/api/pyplot_summary.html#axis-configuration)

|||
|---|---|
|[autoscale]()|Autoscale the axis view to the data (toggle).|
|[axis]()|Convenience method to get or set some axis properties.|
|[box]()|Turn the axes box on or off on the current axes.|
|[grid]()|Configure the grid lines.|
|[locator_params]()|Control behavior of major tick locators.|
|[minorticks_off]()|Remove minor ticks from the Axes.|
|[minorticks_on]()|Display minor ticks on the Axes.|
|[rgrids]()|Get or set the radial gridlines on the current polar plot.|
|[thetagrids]()|Get or set the theta gridlines on the current polar plot.|
|[tick_params]()|Change the appearance of ticks, tick labels, and gridlines.|
|[ticklabel_format]()|Configure the ScalarFormatter used by default for linear Axes.|
|[xlabel]()|Set the label for the x-axis.|
|[xlim]()|Get or set the x limits of the current axes.|
|[xscale]()|Set the xaxis' scale.|
|[xticks]()|Get or set the current tick locations and labels of the x-axis.|
|[ylabel]()|Set the label for the y-axis.|
|[ylim]()|Get or set the y-limits of the current axes.|
|[yscale]()|Set the yaxis' scale.|
|[yticks]()|Get or set the current tick locations and labels of the y-axis.|
|[title]()|Set a title for the Axes.|

## [Layout](https://matplotlib.org/stable/api/pyplot_summary.html#layout)

more [Layout](https://matplotlib.org/stable/api/pyplot_summary.html#layout)

|||
|---|---|
|[margins]()|Set or retrieve autoscaling margins.|
|[subplots_adjust]()|Adjust the subplot layout parameters.|
|[tight_layout]()|Adjust the padding between and around subplots.|

## [Colormapping](https://matplotlib.org/stable/api/pyplot_summary.html#colormapping)

more [Colormapping](https://matplotlib.org/stable/api/pyplot_summary.html#colormapping)

|||
|---|---|
|[clim]()|Set the color limits of the current image.|
|[colorbar]()|Add a colorbar to a plot.|
|[sci]()|Set the current image.|
|[get_cmap]()|Get a colormap instance, defaulting to rc values if name is None.|
|[set_cmap]()|Set the default colormap, and applies it to the current image if any.|
|[imread]()|Read an image from a file into an array.|
|[imsave]()|Colormap and save an array as an image file.|

## [Configuration](https://matplotlib.org/stable/api/pyplot_summary.html#configuration)

more [Configuration](https://matplotlib.org/stable/api/pyplot_summary.html#configuration)

|||
|---|---|
|[rc]()|Set the current rcParams. group is the grouping for the rc, e.g., for lines.linewidth the group is lines, for axes.facecolor, the group is axes, and so on. Group may also be a list or tuple of group names, e.g., (xtick, ytick). kwargs is a dictionary attribute name/value pairs, e.g.,::.|
|[rcdefaults]()|Restore the rcParams from Matplotlib's internal default style.|

## [Output](https://matplotlib.org/stable/api/pyplot_summary.html#output)

more [Output](https://matplotlib.org/stable/api/pyplot_summary.html#output)

|||
|---|---|
|[draw]()|Redraw the current figure.|
|[ioff]()|Disable interactive mode.|
|[ion]()|Enable interactive mode.|
|[pause]()|Run the GUI event loop for interval seconds.|
|[savefig]()|Save the current figure.|
|[show]()|Display all open figures.|

## [Other](https://matplotlib.org/stable/api/pyplot_summary.html#other)

more [Other](https://matplotlib.org/stable/api/pyplot_summary.html#other)

|||
|---|---|
|[waitforbuttonpress]()|Blocking call to interact with the figure.|

