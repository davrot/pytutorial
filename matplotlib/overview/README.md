# Overview of matplotlib.pyplot
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

There a lot of functions in matplotlib.pyplot. Here I list the more important ones. 

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
|[plot](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.plot.html#matplotlib.pyplot.plot)|Plot y versus x as lines and/or markers.|
|[errorbar](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.errorbar.html#matplotlib.pyplot.errorbar)|Plot y versus x as lines and/or markers with attached errorbars.|
|[scatter](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.scatter.html#matplotlib.pyplot.scatter)|A scatter plot of y vs.|
|[step](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.step.html#matplotlib.pyplot.step)|Make a step plot.|
|[loglog](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.loglog.html#matplotlib.pyplot.loglog)|Make a plot with log scaling on both the x- and y-axis.|
|[semilogx](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.semilogx.html#matplotlib.pyplot.semilogx)|Make a plot with log scaling on the x-axis.|
|[semilogy](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.semilogy.html#matplotlib.pyplot.semilogy)|Make a plot with log scaling on the y-axis.|
|[bar](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.bar.html#matplotlib.pyplot.bar)|Make a bar plot.|
|[barh](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.barh.html#matplotlib.pyplot.barh)|Make a horizontal bar plot.|
|[bar_label](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.bar_label.html#matplotlib.pyplot.bar_label)|Label a bar plot.|
|[pie](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.pie.html#matplotlib.pyplot.pie)|Plot a pie chart.|
|[vlines](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.vlines.html#matplotlib.pyplot.vlines)|Plot vertical lines at each x from ymin to ymax.|
|[hlines](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.hlines.html#matplotlib.pyplot.hlines)|Plot horizontal lines at each y from xmin to xmax.|
|[fill](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.fill.html#matplotlib.pyplot.fill)|Plot filled polygons.|
|[polar](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.polar.html#matplotlib.pyplot.polar)|Make a polar plot.|

## [Spans](https://matplotlib.org/stable/api/pyplot_summary.html#spans)
[Spans](https://matplotlib.org/stable/api/pyplot_summary.html#spans)


## [Spectral](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)
[Spectral](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

## [Binned](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

more [Binned](https://matplotlib.org/stable/api/pyplot_summary.html#spectral)

|||
|---|---|
|[hist](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.hist.html#matplotlib.pyplot.hist)|Compute and plot a histogram.|
|[hist2d](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.hist2d.html#matplotlib.pyplot.hist2d)|Make a 2D histogram plot.|

## [Contours](https://matplotlib.org/stable/api/pyplot_summary.html#contours)

|||
|---|---|
|[clabel](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.clabel.html#matplotlib.pyplot.clabel)|Label a contour plot.|
|[contour](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.contour.html#matplotlib.pyplot.contour)|Plot contour lines.|
|[contourf](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.contourf.html#matplotlib.pyplot.contourf)|Plot filled contours.|

## [2D arrays](https://matplotlib.org/stable/api/pyplot_summary.html#d-arrays)

more [2D arrays](https://matplotlib.org/stable/api/pyplot_summary.html#d-arrays)

|||
|---|---|
|[imshow](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.imshow.html#matplotlib.pyplot.imshow)|Display data as an image, i.e., on a 2D regular raster.|

## [Unstructured triangles](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)
[Unstructured triangles](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)

## [Text and annotations](https://matplotlib.org/stable/api/pyplot_summary.html#unstructured-triangles)

|||
|---|---|
|[annotate](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.annotate.html#matplotlib.pyplot.annotate)|Annotate the point xy with text text.|
|[text](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.text.html#matplotlib.pyplot.text)|Add text to the Axes.|
|[figtext](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.figtext.html#matplotlib.pyplot.figtext)|Add text to figure.|
|[table](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.table.html#matplotlib.pyplot.table)|Add a table to an Axes.|
|[arrow](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.arrow.html#matplotlib.pyplot.arrow)|Add an arrow to the Axes.|
|[figlegend](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.figlegend.html#matplotlib.pyplot.figlegend)|Place a legend on the figure.|
|[legend](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.legend.html#matplotlib.pyplot.legend)|Place a legend on the Axes.|

## [Vector fields](https://matplotlib.org/stable/api/pyplot_summary.html#vector-fields)
[Vector fields](https://matplotlib.org/stable/api/pyplot_summary.html#vector-fields)

## [Axis configuration](https://matplotlib.org/stable/api/pyplot_summary.html#axis-configuration)

|||
|---|---|
|[autoscale](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.autoscale.html#matplotlib.pyplot.autoscale)|Autoscale the axis view to the data (toggle).|
|[axis](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.axis.html#matplotlib.pyplot.axis)|Convenience method to get or set some axis properties.|
|[box](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.box.html#matplotlib.pyplot.box)|Turn the axes box on or off on the current axes.|
|[grid](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.grid.html#matplotlib.pyplot.grid)|Configure the grid lines.|
|[locator_params](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.locator_params.html#matplotlib.pyplot.locator_params)|Control behavior of major tick locators.|
|[minorticks_off](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.minorticks_off.html#matplotlib.pyplot.minorticks_off)|Remove minor ticks from the Axes.|
|[minorticks_on](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.minorticks_on.html#matplotlib.pyplot.minorticks_on)|Display minor ticks on the Axes.|
|[rgrids](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.rgrids.html#matplotlib.pyplot.rgrids)|Get or set the radial gridlines on the current polar plot.|
|[thetagrids](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.thetagrids.html#matplotlib.pyplot.thetagrids)|Get or set the theta gridlines on the current polar plot.|
|[tick_params](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.tick_params.html#matplotlib.pyplot.tick_params)|Change the appearance of ticks, tick labels, and gridlines.|
|[ticklabel_format](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.ticklabel_format.html#matplotlib.pyplot.ticklabel_format)|Configure the ScalarFormatter used by default for linear Axes.|
|[xlabel](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xlabel.html#matplotlib.pyplot.xlabel)|Set the label for the x-axis.|
|[xlim](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xlim.html#matplotlib.pyplot.xlim)|Get or set the x limits of the current axes.|
|[xscale](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xscale.html#matplotlib.pyplot.xscale)|Set the xaxis' scale.|
|[xticks](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.xticks.html#matplotlib.pyplot.xticks)|Get or set the current tick locations and labels of the x-axis.|
|[ylabel](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.ylabel.html#matplotlib.pyplot.ylabel)|Set the label for the y-axis.|
|[ylim](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.ylim.html#matplotlib.pyplot.ylim)|Get or set the y-limits of the current axes.|
|[yscale](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.yscale.html#matplotlib.pyplot.yscale)|Set the yaxis' scale.|
|[yticks](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.yticks.html#matplotlib.pyplot.yticks)|Get or set the current tick locations and labels of the y-axis.|
|[title](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.title.html#matplotlib.pyplot.title)|Set a title for the Axes.|

## [Layout](https://matplotlib.org/stable/api/pyplot_summary.html#layout)

more [Layout](https://matplotlib.org/stable/api/pyplot_summary.html#layout)

|||
|---|---|
|[margins](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.margins.html#matplotlib.pyplot.margins)|Set or retrieve autoscaling margins.|
|[subplots_adjust](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.subplots_adjust.html#matplotlib.pyplot.subplots_adjust)|Adjust the subplot layout parameters.|
|[tight_layout](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.tight_layout.html#matplotlib.pyplot.tight_layout)|Adjust the padding between and around subplots.|

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
|[rc](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.rc.html#matplotlib.pyplot.rc)|Set the current rcParams. group is the grouping for the rc, e.g., for lines.linewidth the group is lines, for axes.facecolor, the group is axes, and so on. Group may also be a list or tuple of group names, e.g., (xtick, ytick). kwargs is a dictionary attribute name/value pairs, e.g.,::.|
|[rcdefaults](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.rcdefaults.html#matplotlib.pyplot.rcdefaults)|Restore the rcParams from Matplotlib's internal default style.|

## [Output](https://matplotlib.org/stable/api/pyplot_summary.html#output)

more [Output](https://matplotlib.org/stable/api/pyplot_summary.html#output)

|||
|---|---|
|[draw](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.draw.html#matplotlib.pyplot.draw)|Redraw the current figure.|
|[ioff](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.ioff.html#matplotlib.pyplot.ioff)|Disable interactive mode.|
|[ion](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.ion.html#matplotlib.pyplot.ion)|Enable interactive mode.|
|[pause](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.pause.html#matplotlib.pyplot.pause)|Run the GUI event loop for interval seconds.|
|[savefig](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.savefig.html#matplotlib.pyplot.savefig)|Save the current figure.|
|[show](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.show.html#matplotlib.pyplot.show)|Display all open figures.|

## [Other](https://matplotlib.org/stable/api/pyplot_summary.html#other)

more [Other](https://matplotlib.org/stable/api/pyplot_summary.html#other)

|||
|---|---|
|[waitforbuttonpress](https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.waitforbuttonpress.html#matplotlib.pyplot.waitforbuttonpress)|Blocking call to interact with the figure.|
