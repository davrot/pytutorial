# Overview
{:.no_toc}

<nav markdown="1" class="toc-class">
* TOC
{:toc}
</nav>

## The goal

[scikit-learn](https://scikit-learn.org/stable/index.html) is a machine learning tool kit for data analysis. 

Questions to [David Rotermund](mailto:davrot@uni-bremen.de)


```shell
pip install scikit-learn
```

> * Simple and efficient tools for predictive data analysis
> * Accessible to everybody, and reusable in various contexts
> * Built on NumPy, SciPy, and matplotlib


**I will keep it short and I will mark the most relevant tools in bold**


## [sklearn.base: Base classes and utility functions](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.base)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.base)


## [sklearn.calibration: Probability Calibration](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.calibration)


calibration.CalibratedClassifierCV([...])
Probability calibration with isotonic regression or logistic regression.

calibration.calibration_curve(y_true, y_prob, *)
Compute true and predicted probabilities for a calibration curve.

## [sklearn.cluster: Clustering](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.cluster)

see more [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.cluster)

cluster.AffinityPropagation(*[, damping, ...])
Perform Affinity Propagation Clustering of data.

cluster.AgglomerativeClustering([...])
Agglomerative Clustering.

cluster.Birch(*[, threshold, ...])
Implements the BIRCH clustering algorithm.

cluster.DBSCAN([eps, min_samples, metric, ...])
Perform DBSCAN clustering from vector array or distance matrix.

cluster.HDBSCAN([min_cluster_size, ...])
Cluster data using hierarchical density-based clustering.

cluster.FeatureAgglomeration([n_clusters, ...])
Agglomerate features.

**cluster.KMeans([n_clusters, init, n_init, ...])**
**K-Means clustering.**

cluster.BisectingKMeans([n_clusters, init, ...])
Bisecting K-Means clustering.

**cluster.MiniBatchKMeans([n_clusters, init, ...])**
**Mini-Batch K-Means clustering.**

cluster.MeanShift(*[, bandwidth, seeds, ...])
Mean shift clustering using a flat kernel.

cluster.OPTICS(*[, min_samples, max_eps, ...])
Estimate clustering structure from vector array.

cluster.SpectralClustering([n_clusters, ...])
Apply clustering to a projection of the normalized Laplacian.

cluster.SpectralBiclustering([n_clusters, ...])
Spectral biclustering (Kluger, 2003).

cluster.SpectralCoclustering([n_clusters, ...])
Spectral Co-Clustering algorithm (Dhillon, 2001).


## [sklearn.compose: Composite Estimators](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.compose)

compose.ColumnTransformer(transformers, *[, ...])
Applies transformers to columns of an array or pandas DataFrame.

compose.TransformedTargetRegressor([...])
Meta-estimator to regress on a transformed target.

compose.make_column_transformer(*transformers)
Construct a ColumnTransformer from the given transformers.

compose.make_column_selector([pattern, ...])
Create a callable to select columns to be used with ColumnTransformer.

## [sklearn.covariance: Covariance Estimators](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.covariance)

covariance.EmpiricalCovariance(*[, ...])
Maximum likelihood covariance estimator.

covariance.EllipticEnvelope(*[, ...])
An object for detecting outliers in a Gaussian distributed dataset.

covariance.GraphicalLasso([alpha, mode, ...])
Sparse inverse covariance estimation with an l1-penalized estimator.

covariance.GraphicalLassoCV(*[, alphas, ...])
Sparse inverse covariance w/ cross-validated choice of the l1 penalty.

covariance.LedoitWolf(*[, store_precision, ...])
LedoitWolf Estimator.

covariance.MinCovDet(*[, store_precision, ...])
Minimum Covariance Determinant (MCD): robust estimator of covariance.

covariance.OAS(*[, store_precision, ...])
Oracle Approximating Shrinkage Estimator as proposed in [R69773891e6a6-1].

covariance.ShrunkCovariance(*[, ...])
Covariance estimator with shrinkage.

covariance.empirical_covariance(X, *[, ...])
Compute the Maximum likelihood covariance estimator.

covariance.graphical_lasso(emp_cov, alpha, *)
L1-penalized covariance estimator.

covariance.ledoit_wolf(X, *[, ...])
Estimate the shrunk Ledoit-Wolf covariance matrix.

covariance.ledoit_wolf_shrinkage(X[, ...])
Estimate the shrunk Ledoit-Wolf covariance matrix.

covariance.oas(X, *[, assume_centered])
Estimate covariance with the Oracle Approximating Shrinkage as proposed in [Rca3a42e5ec35-1].

covariance.shrunk_covariance(emp_cov[, ...])
Calculate a covariance matrix shrunk on the diagonal.


## [sklearn.cross_decomposition: Cross decomposition](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.cross_decomposition)

cross_decomposition.CCA([n_components, ...])
Canonical Correlation Analysis, also known as "Mode B" PLS.

cross_decomposition.PLSCanonical([...])
Partial Least Squares transformer and regressor.

cross_decomposition.PLSRegression([...])
PLS regression.

cross_decomposition.PLSSVD([n_components, ...])
Partial Least Square SVD.


## [sklearn.datasets: Datasets](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.datasets)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.datasets)


## [sklearn.decomposition: Matrix Decomposition](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.decomposition)


decomposition.DictionaryLearning([...])
Dictionary learning.

decomposition.FactorAnalysis([n_components, ...])
Factor Analysis (FA).

**decomposition.FastICA([n_components, ...])**
**FastICA: a fast algorithm for Independent Component Analysis.**

decomposition.IncrementalPCA([n_components, ...])
Incremental principal components analysis (IPCA).

decomposition.KernelPCA([n_components, ...])
Kernel Principal component analysis (KPCA) [R396fc7d924b8-1].

decomposition.LatentDirichletAllocation([...])
Latent Dirichlet Allocation with online variational Bayes algorithm.

decomposition.MiniBatchDictionaryLearning([...])
Mini-batch dictionary learning.

decomposition.MiniBatchSparsePCA([...])
Mini-batch Sparse Principal Components Analysis.

decomposition.NMF([n_components, init, ...])
Non-Negative Matrix Factorization (NMF).

decomposition.MiniBatchNMF([n_components, ...])
Mini-Batch Non-Negative Matrix Factorization (NMF).

**decomposition.PCA([n_components, copy, ...])**
**Principal component analysis (PCA).**

decomposition.SparsePCA([n_components, ...])
Sparse Principal Components Analysis (SparsePCA).

decomposition.SparseCoder(dictionary, *[, ...])
Sparse coding.

decomposition.TruncatedSVD([n_components, ...])
Dimensionality reduction using truncated SVD (aka LSA).

decomposition.dict_learning(X, n_components, ...)
Solve a dictionary learning matrix factorization problem.

decomposition.dict_learning_online(X[, ...])
Solve a dictionary learning matrix factorization problem online.

decomposition.fastica(X[, n_components, ...])
Perform Fast Independent Component Analysis.

decomposition.non_negative_factorization(X)
Compute Non-negative Matrix Factorization (NMF).

decomposition.sparse_encode(X, dictionary, *)
Sparse coding.

## [sklearn.discriminant_analysis: Discriminant Analysis](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.discriminant_analysis)

discriminant_analysis.LinearDiscriminantAnalysis([...])
Linear Discriminant Analysis.

discriminant_analysis.QuadraticDiscriminantAnalysis(*)
Quadratic Discriminant Analysis.


## [sklearn.dummy: Dummy estimators](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.dummy)

dummy.DummyClassifier(*[, strategy, ...])
DummyClassifier makes predictions that ignore the input features.

dummy.DummyRegressor(*[, strategy, ...])
Regressor that makes predictions using simple rules.

## [sklearn.ensemble: Ensemble Methods](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.ensemble)

ensemble.AdaBoostClassifier([estimator, ...])
An AdaBoost classifier.

ensemble.AdaBoostRegressor([estimator, ...])
An AdaBoost regressor.

ensemble.BaggingClassifier([estimator, ...])
A Bagging classifier.

ensemble.BaggingRegressor([estimator, ...])
A Bagging regressor.

ensemble.ExtraTreesClassifier([...])
An extra-trees classifier.

ensemble.ExtraTreesRegressor([n_estimators, ...])
An extra-trees regressor.

ensemble.GradientBoostingClassifier(*[, ...])
Gradient Boosting for classification.

ensemble.GradientBoostingRegressor(*[, ...])
Gradient Boosting for regression.

ensemble.IsolationForest(*[, n_estimators, ...])
Isolation Forest Algorithm.

ensemble.RandomForestClassifier([...])
A random forest classifier.

ensemble.RandomForestRegressor([...])
A random forest regressor.

ensemble.RandomTreesEmbedding([...])
An ensemble of totally random trees.

ensemble.StackingClassifier(estimators[, ...])
Stack of estimators with a final classifier.

ensemble.StackingRegressor(estimators[, ...])
Stack of estimators with a final regressor.

ensemble.VotingClassifier(estimators, *[, ...])
Soft Voting/Majority Rule classifier for unfitted estimators.

ensemble.VotingRegressor(estimators, *[, ...])
Prediction voting regressor for unfitted estimators.

ensemble.HistGradientBoostingRegressor([...])
Histogram-based Gradient Boosting Regression Tree.

ensemble.HistGradientBoostingClassifier([...])
Histogram-based Gradient Boosting Classification Tree.

## [sklearn.exceptions: Exceptions and warnings](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.exceptions)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.exceptions)

## [sklearn.experimental: Experimental](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.experimental)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.experimental)


## [sklearn.preprocessing: Preprocessing and Normalization](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.preprocessing)

preprocessing.Binarizer(*[, threshold, copy])
Binarize data (set feature values to 0 or 1) according to a threshold.

preprocessing.FunctionTransformer([func, ...])
Constructs a transformer from an arbitrary callable.

preprocessing.KBinsDiscretizer([n_bins, ...])
Bin continuous data into intervals.

preprocessing.KernelCenterer()
Center an arbitrary kernel matrix 

preprocessing.LabelBinarizer(*[, neg_label, ...])
Binarize labels in a one-vs-all fashion.

preprocessing.LabelEncoder()
Encode target labels with value between 0 and n_classes-1.

preprocessing.MultiLabelBinarizer(*[, ...])
Transform between iterable of iterables and a multilabel format.

preprocessing.MaxAbsScaler(*[, copy])
Scale each feature by its maximum absolute value.

preprocessing.MinMaxScaler([feature_range, ...])
Transform features by scaling each feature to a given range.

preprocessing.Normalizer([norm, copy])
Normalize samples individually to unit norm.

preprocessing.OneHotEncoder(*[, categories, ...])
Encode categorical features as a one-hot numeric array.

preprocessing.OrdinalEncoder(*[, ...])
Encode categorical features as an integer array.

preprocessing.PolynomialFeatures([degree, ...])
Generate polynomial and interaction features.

preprocessing.PowerTransformer([method, ...])
Apply a power transform featurewise to make data more Gaussian-like.

preprocessing.QuantileTransformer(*[, ...])
Transform features using quantiles information.

preprocessing.RobustScaler(*[, ...])
Scale features using statistics that are robust to outliers.

preprocessing.SplineTransformer([n_knots, ...])
Generate univariate B-spline bases for features.

preprocessing.StandardScaler(*[, copy, ...])
Standardize features by removing the mean and scaling to unit variance.

preprocessing.TargetEncoder([categories, ...])
Target Encoder for regression and classification targets.

preprocessing.add_dummy_feature(X[, value])
Augment dataset with an additional dummy feature.

preprocessing.binarize(X, *[, threshold, copy])
Boolean thresholding of array-like or scipy.sparse matrix.

preprocessing.label_binarize(y, *, classes)
Binarize labels in a one-vs-all fashion.

preprocessing.maxabs_scale(X, *[, axis, copy])
Scale each feature to the [-1, 1] range without breaking the sparsity.

preprocessing.minmax_scale(X[, ...])
Transform features by scaling each feature to a given range.

preprocessing.normalize(X[, norm, axis, ...])
Scale input vectors individually to unit norm (vector length).

preprocessing.quantile_transform(X, *[, ...])
Transform features using quantiles information.

preprocessing.robust_scale(X, *[, axis, ...])
Standardize a dataset along any axis.

preprocessing.scale(X, *[, axis, with_mean, ...])
Standardize a dataset along any axis.

preprocessing.power_transform(X[, method, ...])
Parametric, monotonic transformation to make data more Gaussian-like.



## [sklearn.random_projection: Random projection](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.random_projection)

random_projection.GaussianRandomProjection([...])
Reduce dimensionality through Gaussian random projection.

random_projection.SparseRandomProjection([...])
Reduce dimensionality through sparse random projection.

random_projection.johnson_lindenstrauss_min_dim(...)
Find a 'safe' number of components to randomly project to.

## [sklearn.semi_supervised: Semi-Supervised Learning](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.semi_supervised)

semi_supervised.LabelPropagation([kernel, ...])
Label Propagation classifier.

semi_supervised.LabelSpreading([kernel, ...])
LabelSpreading model for semi-supervised learning.

semi_supervised.SelfTrainingClassifier(...)
Self-training classifier.



## [sklearn.svm: Support Vector Machines](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.svm)

svm.LinearSVC([penalty, loss, dual, tol, C, ...])
Linear Support Vector Classification.

svm.LinearSVR(*[, epsilon, tol, C, loss, ...])
Linear Support Vector Regression.

svm.NuSVC(*[, nu, kernel, degree, gamma, ...])
Nu-Support Vector Classification.

svm.NuSVR(*[, nu, C, kernel, degree, gamma, ...])
Nu Support Vector Regression.

svm.OneClassSVM(*[, kernel, degree, gamma, ...])
Unsupervised Outlier Detection.

svm.SVC(*[, C, kernel, degree, gamma, ...])
C-Support Vector Classification.

svm.SVR(*[, kernel, degree, gamma, coef0, ...])
Epsilon-Support Vector Regression.

svm.l1_min_c(X, y, *[, loss, fit_intercept, ...])
Return the lowest bound for C.



## [sklearn.tree: Decision Trees](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.tree)

tree.DecisionTreeClassifier(*[, criterion, ...])
A decision tree classifier.

tree.DecisionTreeRegressor(*[, criterion, ...])
A decision tree regressor.

tree.ExtraTreeClassifier(*[, criterion, ...])
An extremely randomized tree classifier.

tree.ExtraTreeRegressor(*[, criterion, ...])
An extremely randomized tree regressor.

tree.export_graphviz(decision_tree[, ...])
Export a decision tree in DOT format.

tree.export_text(decision_tree, *[, ...])
Build a text report showing the rules of a decision tree.

tree.plot_tree(decision_tree, *[, ...])
Plot a decision tree.

## [sklearn.utils: Utilities](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.utils)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.utils)
