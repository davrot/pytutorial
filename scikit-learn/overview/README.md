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



### Classes

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

### Functions

cluster.affinity_propagation(S, *[, ...])
Perform Affinity Propagation Clustering of data.

cluster.cluster_optics_dbscan(*, ...)
Perform DBSCAN extraction for an arbitrary epsilon.

cluster.cluster_optics_xi(*, reachability, ...)
Automatically extract clusters according to the Xi-steep method.

cluster.compute_optics_graph(X, *, ...)
Compute the OPTICS reachability graph.

cluster.dbscan(X[, eps, min_samples, ...])
Perform DBSCAN clustering from vector array or distance matrix.

cluster.estimate_bandwidth(X, *[, quantile, ...])
Estimate the bandwidth to use with the mean-shift algorithm.

cluster.k_means(X, n_clusters, *[, ...])
Perform K-means clustering algorithm.

cluster.kmeans_plusplus(X, n_clusters, *[, ...])
Init n_clusters seeds according to k-means++.

cluster.mean_shift(X, *[, bandwidth, seeds, ...])
Perform mean shift clustering of data using a flat kernel.

cluster.spectral_clustering(affinity, *[, ...])
Apply clustering to a projection of the normalized Laplacian.

cluster.ward_tree(X, *[, connectivity, ...])
Ward clustering based on a Feature matrix.


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

## [sklearn.feature_extraction: Feature Extraction](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.feature_extraction)

feature_extraction.DictVectorizer(*[, ...])
Transforms lists of feature-value mappings to vectors.

feature_extraction.FeatureHasher([...])
Implements feature hashing, aka the hashing trick.

### From images

feature_extraction.image.extract_patches_2d(...)
Reshape a 2D image into a collection of patches.

feature_extraction.image.grid_to_graph(n_x, n_y)
Graph of the pixel-to-pixel connections.

feature_extraction.image.img_to_graph(img, *)
Graph of the pixel-to-pixel gradient connections.

feature_extraction.image.reconstruct_from_patches_2d(...)
Reconstruct the image from all of its patches.

feature_extraction.image.PatchExtractor(*[, ...])
Extracts patches from a collection of images.

### From text

feature_extraction.text.CountVectorizer(*[, ...])
Convert a collection of text documents to a matrix of token counts.

feature_extraction.text.HashingVectorizer(*)
Convert a collection of text documents to a matrix of token occurrences.

feature_extraction.text.TfidfTransformer(*)
Transform a count matrix to a normalized tf or tf-idf representation.

feature_extraction.text.TfidfVectorizer(*[, ...])
Convert a collection of raw documents to a matrix of TF-IDF features.

## [sklearn.feature_selection: Feature Selection](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.feature_selection)

feature_selection.GenericUnivariateSelect([...])
Univariate feature selector with configurable strategy.

feature_selection.SelectPercentile([...])
Select features according to a percentile of the highest scores.

feature_selection.SelectKBest([score_func, k])
Select features according to the k highest scores.

feature_selection.SelectFpr([score_func, alpha])
Filter: Select the pvalues below alpha based on a FPR test.

feature_selection.SelectFdr([score_func, alpha])
Filter: Select the p-values for an estimated false discovery rate.

feature_selection.SelectFromModel(estimator, *)
Meta-transformer for selecting features based on importance weights.

feature_selection.SelectFwe([score_func, alpha])
Filter: Select the p-values corresponding to Family-wise error rate.

feature_selection.SequentialFeatureSelector(...)
Transformer that performs Sequential Feature Selection.

feature_selection.RFE(estimator, *[, ...])
Feature ranking with recursive feature elimination.

feature_selection.RFECV(estimator, *[, ...])
Recursive feature elimination with cross-validation to select features.

feature_selection.VarianceThreshold([threshold])
Feature selector that removes all low-variance features.

feature_selection.chi2(X, y)
Compute chi-squared stats between each non-negative feature and class.

feature_selection.f_classif(X, y)
Compute the ANOVA F-value for the provided sample.

feature_selection.f_regression(X, y, *[, ...])
Univariate linear regression tests returning F-statistic and p-values.

feature_selection.r_regression(X, y, *[, ...])
Compute Pearson's r for each features and the target.

feature_selection.mutual_info_classif(X, y, *)
Estimate mutual information for a discrete target variable.

feature_selection.mutual_info_regression(X, y, *)
Estimate mutual information for a continuous target variable.

## [sklearn.gaussian_process: Gaussian Processes]()

gaussian_process.GaussianProcessClassifier([...])
Gaussian process classification (GPC) based on Laplace approximation.

gaussian_process.GaussianProcessRegressor([...])
Gaussian process regression (GPR).


### Kernels

gaussian_process.kernels.CompoundKernel(kernels)
Kernel which is composed of a set of other kernels.

gaussian_process.kernels.ConstantKernel([...])
Constant kernel.

gaussian_process.kernels.DotProduct([...])
Dot-Product kernel.

gaussian_process.kernels.ExpSineSquared([...])
Exp-Sine-Squared kernel (aka periodic kernel).

gaussian_process.kernels.Exponentiation(...)
The Exponentiation kernel takes one base kernel and a scalar parameter  and combines them via

gaussian_process.kernels.Hyperparameter(...)
A kernel hyperparameter's specification in form of a namedtuple.

gaussian_process.kernels.Kernel()
Base class for all kernels.

gaussian_process.kernels.Matern([...])
Matern kernel.

gaussian_process.kernels.PairwiseKernel([...])
Wrapper for kernels in sklearn.metrics.pairwise.

gaussian_process.kernels.Product(k1, k2)
The Product kernel takes two kernels k1 and k2 and combines them via

gaussian_process.kernels.RBF([length_scale, ...])
Radial basis function kernel (aka squared-exponential kernel).

gaussian_process.kernels.RationalQuadratic([...])
Rational Quadratic kernel.

gaussian_process.kernels.Sum(k1, k2)
The Sum kernel takes two kernels k1 and k2 and combines them via

gaussian_process.kernels.WhiteKernel([...])
White kernel.

## [sklearn.impute: Impute](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.impute)

impute.SimpleImputer(*[, missing_values, ...])
Univariate imputer for completing missing values with simple strategies.

impute.IterativeImputer([estimator, ...])
Multivariate imputer that estimates each feature from all the others.

impute.MissingIndicator(*[, missing_values, ...])
Binary indicators for missing values.

impute.KNNImputer(*[, missing_values, ...])
Imputation for completing missing values using k-Nearest Neighbors.

## [sklearn.inspection: Inspection](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.inspection)

inspection.partial_dependence(estimator, X, ...)
Partial dependence of features.

inspection.permutation_importance(estimator, ...)
Permutation importance for feature evaluation [Rd9e56ef97513-BRE].

### Plotting

inspection.DecisionBoundaryDisplay(*, xx0, ...)
Decisions boundary visualization.

inspection.PartialDependenceDisplay(...[, ...])
Partial Dependence Plot (PDP).


## [sklearn.isotonic: Isotonic regression](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.isotonic)


isotonic.IsotonicRegression(*[, y_min, ...])
Isotonic regression model.

isotonic.check_increasing(x, y)
Determine whether y is monotonically correlated with x.

isotonic.isotonic_regression(y, *[, ...])
Solve the isotonic regression model.

## [sklearn.kernel_approximation: Kernel Approximation](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.kernel_approximation)

kernel_approximation.AdditiveChi2Sampler(*)
Approximate feature map for additive chi2 kernel.

kernel_approximation.Nystroem([kernel, ...])
Approximate a kernel map using a subset of the training data.

kernel_approximation.PolynomialCountSketch(*)
Polynomial kernel approximation via Tensor Sketch.

kernel_approximation.RBFSampler(*[, gamma, ...])
Approximate a RBF kernel feature map using random Fourier features.

kernel_approximation.SkewedChi2Sampler(*[, ...])
Approximate feature map for "skewed chi-squared" kernel.

## [sklearn.kernel_ridge: Kernel Ridge Regression](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.kernel_ridge)

kernel_ridge.KernelRidge([alpha, kernel, ...])
Kernel ridge regression.

## [sklearn.linear_model: Linear Models](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.linear_model)

### Linear classifiers

linear_model.LogisticRegression([penalty, ...])
Logistic Regression (aka logit, MaxEnt) classifier.

linear_model.LogisticRegressionCV(*[, Cs, ...])
Logistic Regression CV (aka logit, MaxEnt) classifier.

linear_model.PassiveAggressiveClassifier(*)
Passive Aggressive Classifier.

linear_model.Perceptron(*[, penalty, alpha, ...])
Linear perceptron classifier.

linear_model.RidgeClassifier([alpha, ...])
Classifier using Ridge regression.

linear_model.RidgeClassifierCV([alphas, ...])
Ridge classifier with built-in cross-validation.

linear_model.SGDClassifier([loss, penalty, ...])
Linear classifiers (SVM, logistic regression, etc.) with SGD training.

linear_model.SGDOneClassSVM([nu, ...])
Solves linear One-Class SVM using Stochastic Gradient Descent.

### Classical linear regressors

linear_model.LinearRegression(*[, ...])
Ordinary least squares Linear Regression.

linear_model.Ridge([alpha, fit_intercept, ...])
Linear least squares with l2 regularization.

linear_model.RidgeCV([alphas, ...])
Ridge regression with built-in cross-validation.

linear_model.SGDRegressor([loss, penalty, ...])
Linear model fitted by minimizing a regularized empirical loss with SGD.

### Regressors with variable selection


linear_model.ElasticNet([alpha, l1_ratio, ...])
Linear regression with combined L1 and L2 priors as regularizer.

linear_model.ElasticNetCV(*[, l1_ratio, ...])
Elastic Net model with iterative fitting along a regularization path.

linear_model.Lars(*[, fit_intercept, ...])
Least Angle Regression model a.k.a.

linear_model.LarsCV(*[, fit_intercept, ...])
Cross-validated Least Angle Regression model.

linear_model.Lasso([alpha, fit_intercept, ...])
Linear Model trained with L1 prior as regularizer (aka the Lasso).

linear_model.LassoCV(*[, eps, n_alphas, ...])
Lasso linear model with iterative fitting along a regularization path.

linear_model.LassoLars([alpha, ...])
Lasso model fit with Least Angle Regression a.k.a.

linear_model.LassoLarsCV(*[, fit_intercept, ...])
Cross-validated Lasso, using the LARS algorithm.

linear_model.LassoLarsIC([criterion, ...])
Lasso model fit with Lars using BIC or AIC for model selection.

linear_model.OrthogonalMatchingPursuit(*[, ...])
Orthogonal Matching Pursuit model (OMP).

linear_model.OrthogonalMatchingPursuitCV(*)
Cross-validated Orthogonal Matching Pursuit model (OMP).

### Bayesian regressors

linear_model.ARDRegression(*[, max_iter, ...])
Bayesian ARD regression.

linear_model.BayesianRidge(*[, max_iter, ...])
Bayesian ridge regression.

### Multi-task linear regressors with variable selection

linear_model.MultiTaskElasticNet([alpha, ...])
Multi-task ElasticNet model trained with L1/L2 mixed-norm as regularizer.

linear_model.MultiTaskElasticNetCV(*[, ...])
Multi-task L1/L2 ElasticNet with built-in cross-validation.

linear_model.MultiTaskLasso([alpha, ...])
Multi-task Lasso model trained with L1/L2 mixed-norm as regularizer.

linear_model.MultiTaskLassoCV(*[, eps, ...])
Multi-task Lasso model trained with L1/L2 mixed-norm as regularizer.

### Outlier-robust regressors


linear_model.HuberRegressor(*[, epsilon, ...])
L2-regularized linear regression model that is robust to outliers.

linear_model.QuantileRegressor(*[, ...])
Linear regression model that predicts conditional quantiles.

linear_model.RANSACRegressor([estimator, ...])
RANSAC (RANdom SAmple Consensus) algorithm.

linear_model.TheilSenRegressor(*[, ...])
Theil-Sen Estimator: robust multivariate regression model.

### Generalized linear models (GLM) for regression

linear_model.PoissonRegressor(*[, alpha, ...])
Generalized Linear Model with a Poisson distribution.

linear_model.TweedieRegressor(*[, power, ...])
Generalized Linear Model with a Tweedie distribution.

linear_model.GammaRegressor(*[, alpha, ...])
Generalized Linear Model with a Gamma distribution.

### Miscellaneous

linear_model.PassiveAggressiveRegressor(*[, ...])
Passive Aggressive Regressor.

linear_model.enet_path(X, y, *[, l1_ratio, ...])
Compute elastic net path with coordinate descent.

linear_model.lars_path(X, y[, Xy, Gram, ...])
Compute Least Angle Regression or Lasso path using the LARS algorithm [1].

linear_model.lars_path_gram(Xy, Gram, *, ...)
The lars_path in the sufficient stats mode [1].

linear_model.lasso_path(X, y, *[, eps, ...])
Compute Lasso path with coordinate descent.

linear_model.orthogonal_mp(X, y, *[, ...])
Orthogonal Matching Pursuit (OMP).

linear_model.orthogonal_mp_gram(Gram, Xy, *)
Gram Orthogonal Matching Pursuit (OMP).

linear_model.ridge_regression(X, y, alpha, *)
Solve the ridge equation by the method of normal equations.

## [sklearn.manifold: Manifold Learning](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.manifold)


manifold.Isomap(*[, n_neighbors, radius, ...])
Isomap Embedding.

manifold.LocallyLinearEmbedding(*[, ...])
Locally Linear Embedding.

manifold.MDS([n_components, metric, n_init, ...])
Multidimensional scaling.

manifold.SpectralEmbedding([n_components, ...])
Spectral embedding for non-linear dimensionality reduction.

manifold.TSNE([n_components, perplexity, ...])
T-distributed Stochastic Neighbor Embedding.

manifold.locally_linear_embedding(X, *, ...)
Perform a Locally Linear Embedding analysis on the data.

manifold.smacof(dissimilarities, *[, ...])
Compute multidimensional scaling using the SMACOF algorithm.

manifold.spectral_embedding(adjacency, *[, ...])
Project the sample on the first eigenvectors of the graph Laplacian.

manifold.trustworthiness(X, X_embedded, *[, ...])
Indicate to what extent the local structure is retained.



## [sklearn.metrics: Metrics](https://scikit-learn.org/stable/modules/classes.html#sklearn-metrics-metrics)

### Model Selection Interface

metrics.check_scoring(estimator[, scoring, ...])
Determine scorer from user options.

metrics.get_scorer(scoring)
Get a scorer from string.

metrics.get_scorer_names()
Get the names of all available scorers.

metrics.make_scorer(score_func, *[, ...])
Make a scorer from a performance metric or loss function.

### Classification metrics

metrics.accuracy_score(y_true, y_pred, *[, ...])
Accuracy classification score.

metrics.auc(x, y)
Compute Area Under the Curve (AUC) using the trapezoidal rule.

metrics.average_precision_score(y_true, ...)
Compute average precision (AP) from prediction scores.

metrics.balanced_accuracy_score(y_true, ...)
Compute the balanced accuracy.

metrics.brier_score_loss(y_true, y_prob, *)
Compute the Brier score loss.

metrics.class_likelihood_ratios(y_true, ...)
Compute binary classification positive and negative likelihood ratios.

metrics.classification_report(y_true, y_pred, *)
Build a text report showing the main classification metrics.

metrics.cohen_kappa_score(y1, y2, *[, ...])
Compute Cohen's kappa: a statistic that measures inter-annotator agreement.

metrics.confusion_matrix(y_true, y_pred, *)
Compute confusion matrix to evaluate the accuracy of a classification.

metrics.dcg_score(y_true, y_score, *[, k, ...])
Compute Discounted Cumulative Gain.

metrics.det_curve(y_true, y_score[, ...])
Compute error rates for different probability thresholds.

metrics.f1_score(y_true, y_pred, *[, ...])
Compute the F1 score, also known as balanced F-score or F-measure.

metrics.fbeta_score(y_true, y_pred, *, beta)
Compute the F-beta score.

metrics.hamming_loss(y_true, y_pred, *[, ...])
Compute the average Hamming loss.

metrics.hinge_loss(y_true, pred_decision, *)
Average hinge loss (non-regularized).

metrics.jaccard_score(y_true, y_pred, *[, ...])
Jaccard similarity coefficient score.

metrics.log_loss(y_true, y_pred, *[, eps, ...])
Log loss, aka logistic loss or cross-entropy loss.

metrics.matthews_corrcoef(y_true, y_pred, *)
Compute the Matthews correlation coefficient (MCC).

metrics.multilabel_confusion_matrix(y_true, ...)
Compute a confusion matrix for each class or sample.

metrics.ndcg_score(y_true, y_score, *[, k, ...])
Compute Normalized Discounted Cumulative Gain.

metrics.precision_recall_curve(y_true, ...)
Compute precision-recall pairs for different probability thresholds.

metrics.precision_recall_fscore_support(...)
Compute precision, recall, F-measure and support for each class.

metrics.precision_score(y_true, y_pred, *[, ...])
Compute the precision.

metrics.recall_score(y_true, y_pred, *[, ...])
Compute the recall.

metrics.roc_auc_score(y_true, y_score, *[, ...])
Compute Area Under the Receiver Operating Characteristic Curve (ROC AUC)     from prediction scores.

metrics.roc_curve(y_true, y_score, *[, ...])
Compute Receiver operating characteristic (ROC).

metrics.top_k_accuracy_score(y_true, y_score, *)
Top-k Accuracy classification score.

metrics.zero_one_loss(y_true, y_pred, *[, ...])
Zero-one classification loss.

### Regression metrics

metrics.explained_variance_score(y_true, ...)
Explained variance regression score function.

metrics.max_error(y_true, y_pred)
The max_error metric calculates the maximum residual error.

metrics.mean_absolute_error(y_true, y_pred, *)
Mean absolute error regression loss.

metrics.mean_squared_error(y_true, y_pred, *)
Mean squared error regression loss.

metrics.mean_squared_log_error(y_true, y_pred, *)
Mean squared logarithmic error regression loss.

metrics.median_absolute_error(y_true, y_pred, *)
Median absolute error regression loss.

metrics.mean_absolute_percentage_error(...)
Mean absolute percentage error (MAPE) regression loss.

metrics.r2_score(y_true, y_pred, *[, ...])
R^2 (coefficient of determination) regression score function.

metrics.mean_poisson_deviance(y_true, y_pred, *)
Mean Poisson deviance regression loss.

metrics.mean_gamma_deviance(y_true, y_pred, *)
Mean Gamma deviance regression loss.

metrics.mean_tweedie_deviance(y_true, y_pred, *)
Mean Tweedie deviance regression loss.

metrics.d2_tweedie_score(y_true, y_pred, *)
D^2 regression score function, fraction of Tweedie deviance explained.

metrics.mean_pinball_loss(y_true, y_pred, *)
Pinball loss for quantile regression.

metrics.d2_pinball_score(y_true, y_pred, *)
D^2 regression score function, fraction of pinball loss explained.

metrics.d2_absolute_error_score(y_true, ...)
D^2 regression score function, fraction of absolute error explained.


### Multilabel ranking metrics

metrics.coverage_error(y_true, y_score, *[, ...])
Coverage error measure.

metrics.label_ranking_average_precision_score(...)
Compute ranking-based average precision.

metrics.label_ranking_loss(y_true, y_score, *)
Compute Ranking loss measure.


### Clustering metrics

metrics.adjusted_mutual_info_score(...[, ...])
Adjusted Mutual Information between two clusterings.

metrics.adjusted_rand_score(labels_true, ...)
Rand index adjusted for chance.

metrics.calinski_harabasz_score(X, labels)
Compute the Calinski and Harabasz score.

metrics.davies_bouldin_score(X, labels)
Compute the Davies-Bouldin score.

metrics.completeness_score(labels_true, ...)
Compute completeness metric of a cluster labeling given a ground truth.

metrics.cluster.contingency_matrix(...[, ...])
Build a contingency matrix describing the relationship between labels.

metrics.cluster.pair_confusion_matrix(...)
Pair confusion matrix arising from two clusterings [R9ca8fd06d29a-1].

metrics.fowlkes_mallows_score(labels_true, ...)
Measure the similarity of two clusterings of a set of points.

metrics.homogeneity_completeness_v_measure(...)
Compute the homogeneity and completeness and V-Measure scores at once.

metrics.homogeneity_score(labels_true, ...)
Homogeneity metric of a cluster labeling given a ground truth.

metrics.mutual_info_score(labels_true, ...)
Mutual Information between two clusterings.

metrics.normalized_mutual_info_score(...[, ...])
Normalized Mutual Information between two clusterings.

metrics.rand_score(labels_true, labels_pred)
Rand index.

metrics.silhouette_score(X, labels, *[, ...])
Compute the mean Silhouette Coefficient of all samples.

metrics.silhouette_samples(X, labels, *[, ...])
Compute the Silhouette Coefficient for each sample.

metrics.v_measure_score(labels_true, ...[, beta])
V-measure cluster labeling given a ground truth.

### Biclustering metrics

metrics.consensus_score(a, b, *[, similarity])
The similarity of two sets of biclusters.

### Distance metrics

metrics.DistanceMetric
Uniform interface for fast distance metric functions.

### Pairwise metrics

metrics.pairwise.additive_chi2_kernel(X[, Y])
Compute the additive chi-squared kernel between observations in X and Y.

metrics.pairwise.chi2_kernel(X[, Y, gamma])
Compute the exponential chi-squared kernel between X and Y.

metrics.pairwise.cosine_similarity(X[, Y, ...])
Compute cosine similarity between samples in X and Y.

metrics.pairwise.cosine_distances(X[, Y])
Compute cosine distance between samples in X and Y.

metrics.pairwise.distance_metrics()
Valid metrics for pairwise_distances.

metrics.pairwise.euclidean_distances(X[, Y, ...])
Compute the distance matrix between each pair from a vector array X and Y.

metrics.pairwise.haversine_distances(X[, Y])
Compute the Haversine distance between samples in X and Y.

metrics.pairwise.kernel_metrics()
Valid metrics for pairwise_kernels.

metrics.pairwise.laplacian_kernel(X[, Y, gamma])
Compute the laplacian kernel between X and Y.

metrics.pairwise.linear_kernel(X[, Y, ...])
Compute the linear kernel between X and Y.

metrics.pairwise.manhattan_distances(X[, Y, ...])
Compute the L1 distances between the vectors in X and Y.

metrics.pairwise.nan_euclidean_distances(X)
Calculate the euclidean distances in the presence of missing values.

metrics.pairwise.pairwise_kernels(X[, Y, ...])
Compute the kernel between arrays X and optional array Y.

metrics.pairwise.polynomial_kernel(X[, Y, ...])
Compute the polynomial kernel between X and Y.

metrics.pairwise.rbf_kernel(X[, Y, gamma])
Compute the rbf (gaussian) kernel between X and Y.

metrics.pairwise.sigmoid_kernel(X[, Y, ...])
Compute the sigmoid kernel between X and Y.

metrics.pairwise.paired_euclidean_distances(X, Y)
Compute the paired euclidean distances between X and Y.

metrics.pairwise.paired_manhattan_distances(X, Y)
Compute the paired L1 distances between X and Y.

metrics.pairwise.paired_cosine_distances(X, Y)
Compute the paired cosine distances between X and Y.

metrics.pairwise.paired_distances(X, Y, *[, ...])
Compute the paired distances between X and Y.

metrics.pairwise_distances(X[, Y, metric, ...])
Compute the distance matrix from a vector array X and optional Y.

metrics.pairwise_distances_argmin(X, Y, *[, ...])
Compute minimum distances between one point and a set of points.

metrics.pairwise_distances_argmin_min(X, Y, *)
Compute minimum distances between one point and a set of points.

metrics.pairwise_distances_chunked(X[, Y, ...])
Generate a distance matrix chunk by chunk with optional reduction.

### Plotting

metrics.ConfusionMatrixDisplay(...[, ...])
Confusion Matrix visualization.

metrics.DetCurveDisplay(*, fpr, fnr[, ...])
DET curve visualization.

metrics.PrecisionRecallDisplay(precision, ...)
Precision Recall visualization.

metrics.PredictionErrorDisplay(*, y_true, y_pred)
Visualization of the prediction error of a regression model.

metrics.RocCurveDisplay(*, fpr, tpr[, ...])
ROC Curve visualization.

calibration.CalibrationDisplay(prob_true, ...)
Calibration curve (also known as reliability diagram) visualization.



## [sklearn.mixture: Gaussian Mixture Models](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.mixture)

mixture.BayesianGaussianMixture(*[, ...])
Variational Bayesian estimation of a Gaussian mixture.

mixture.GaussianMixture([n_components, ...])
Gaussian Mixture.


## [sklearn.model_selection: Model Selection](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.model_selection)

### Splitter Classes

model_selection.GroupKFold([n_splits])
K-fold iterator variant with non-overlapping groups.

model_selection.GroupShuffleSplit([...])
Shuffle-Group(s)-Out cross-validation iterator

model_selection.KFold([n_splits, shuffle, ...])
K-Folds cross-validator

model_selection.LeaveOneGroupOut()
Leave One Group Out cross-validator

model_selection.LeavePGroupsOut(n_groups)
Leave P Group(s) Out cross-validator

model_selection.LeaveOneOut()
Leave-One-Out cross-validator

model_selection.LeavePOut(p)
Leave-P-Out cross-validator

model_selection.PredefinedSplit(test_fold)
Predefined split cross-validator

model_selection.RepeatedKFold(*[, n_splits, ...])
Repeated K-Fold cross validator.

model_selection.RepeatedStratifiedKFold(*[, ...])
Repeated Stratified K-Fold cross validator.

model_selection.ShuffleSplit([n_splits, ...])
Random permutation cross-validator

model_selection.StratifiedKFold([n_splits, ...])
Stratified K-Folds cross-validator.

model_selection.StratifiedShuffleSplit([...])
Stratified ShuffleSplit cross-validator

model_selection.StratifiedGroupKFold([...])
Stratified K-Folds iterator variant with non-overlapping groups.

model_selection.TimeSeriesSplit([n_splits, ...])
Time Series cross-validator

### Splitter Functions

model_selection.check_cv([cv, y, classifier])
Input checker utility for building a cross-validator.

model_selection.train_test_split(*arrays[, ...])
Split arrays or matrices into random train and test subsets.

##ä Hyper-parameter optimizers

model_selection.GridSearchCV(estimator, ...)
Exhaustive search over specified parameter values for an estimator.

model_selection.HalvingGridSearchCV(...[, ...])
Search over specified parameter values with successive halving.

model_selection.ParameterGrid(param_grid)
Grid of parameters with a discrete number of values for each.

model_selection.ParameterSampler(...[, ...])
Generator on parameters sampled from given distributions.

model_selection.RandomizedSearchCV(...[, ...])
Randomized search on hyper parameters.

model_selection.HalvingRandomSearchCV(...[, ...])
Randomized search on hyper parameters.


### Model validation

model_selection.cross_validate(estimator, X)
Evaluate metric(s) by cross-validation and also record fit/score times.

model_selection.cross_val_predict(estimator, X)
Generate cross-validated estimates for each input data point.

model_selection.cross_val_score(estimator, X)
Evaluate a score by cross-validation.

model_selection.learning_curve(estimator, X, ...)
Learning curve.

model_selection.permutation_test_score(...)
Evaluate the significance of a cross-validated score with permutations.

model_selection.validation_curve(estimator, ...)
Validation curve.


### Visualization

model_selection.LearningCurveDisplay(*, ...)
Learning Curve visualization.

model_selection.ValidationCurveDisplay(*, ...)
Validation Curve visualization.



## [sklearn.multiclass: Multiclass classification](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.multiclass)

multiclass.OneVsRestClassifier(estimator, *)
One-vs-the-rest (OvR) multiclass strategy.

multiclass.OneVsOneClassifier(estimator, *)
One-vs-one multiclass strategy.

multiclass.OutputCodeClassifier(estimator, *)
(Error-Correcting) Output-Code multiclass strategy.

## [sklearn.multioutput: Multioutput regression and classification](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.multioutput)


multioutput.ClassifierChain(base_estimator, *)
A multi-label model that arranges binary classifiers into a chain.

multioutput.MultiOutputRegressor(estimator, *)
Multi target regression.

multioutput.MultiOutputClassifier(estimator, *)
Multi target classification.

multioutput.RegressorChain(base_estimator, *)
A multi-label model that arranges regressions into a chain.


## [sklearn.naive_bayes: Naive Bayes](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.naive_bayes)

naive_bayes.BernoulliNB(*[, alpha, ...])
Naive Bayes classifier for multivariate Bernoulli models.

naive_bayes.CategoricalNB(*[, alpha, ...])
Naive Bayes classifier for categorical features.

naive_bayes.ComplementNB(*[, alpha, ...])
The Complement Naive Bayes classifier described in Rennie et al. (2003).

naive_bayes.GaussianNB(*[, priors, ...])
Gaussian Naive Bayes (GaussianNB).

naive_bayes.MultinomialNB(*[, alpha, ...])
Naive Bayes classifier for multinomial models.



## [sklearn.neighbors: Nearest Neighbors](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.neighbors)

neighbors.BallTree(X[, leaf_size, metric])
BallTree for fast generalized N-point problems

neighbors.KDTree(X[, leaf_size, metric])
KDTree for fast generalized N-point problems

neighbors.KernelDensity(*[, bandwidth, ...])
Kernel Density Estimation.

**neighbors.KNeighborsClassifier([...])**
**Classifier implementing the k-nearest neighbors vote.**

neighbors.KNeighborsRegressor([n_neighbors, ...])
Regression based on k-nearest neighbors.

neighbors.KNeighborsTransformer(*[, mode, ...])
Transform X into a (weighted) graph of k nearest neighbors.

neighbors.LocalOutlierFactor([n_neighbors, ...])
Unsupervised Outlier Detection using the Local Outlier Factor (LOF).

neighbors.RadiusNeighborsClassifier([...])
Classifier implementing a vote among neighbors within a given radius.

neighbors.RadiusNeighborsRegressor([radius, ...])
Regression based on neighbors within a fixed radius.

neighbors.RadiusNeighborsTransformer(*[, ...])
Transform X into a (weighted) graph of neighbors nearer than a radius.

neighbors.NearestCentroid([metric, ...])
Nearest centroid classifier.

neighbors.NearestNeighbors(*[, n_neighbors, ...])
Unsupervised learner for implementing neighbor searches.

neighbors.NeighborhoodComponentsAnalysis([...])
Neighborhood Components Analysis.

neighbors.kneighbors_graph(X, n_neighbors, *)
Compute the (weighted) graph of k-Neighbors for points in X.

neighbors.radius_neighbors_graph(X, radius, *)
Compute the (weighted) graph of Neighbors for points in X.

neighbors.sort_graph_by_row_values(graph[, ...])
Sort a sparse graph such that each row is stored with increasing values.


## [sklearn.neural_network: Neural network models](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.neural_network)

pipeline.FeatureUnion(transformer_list, *[, ...])
Concatenates results of multiple transformer objects.

pipeline.Pipeline(steps, *[, memory, verbose])
Pipeline of transforms with a final estimator.

pipeline.make_pipeline(*steps[, memory, verbose])
Construct a Pipeline from the given estimators.

pipeline.make_union(*transformers[, n_jobs, ...])
Construct a FeatureUnion from the given transformers.



## [sklearn.pipeline: Pipeline](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.pipeline)

see [here](https://scikit-learn.org/stable/modules/classes.html#module-sklearn.pipeline)

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
