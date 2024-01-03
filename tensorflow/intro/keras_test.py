from tensorflow import keras
from DataGenerator import DataGenerator

number_of_classes: int = 10
size_of_batch_test: int = 100
model_id: int = 49

test_data = DataGenerator(
    train=False,
    size_of_batch=size_of_batch_test,
    number_of_classes=number_of_classes,
    do_shuffle=False,
)

keras.backend.clear_session()

network = keras.models.load_model("./Model_" + str(model_id) + ".h5")

test_loss, test_acc = network.evaluate(x=test_data)

print(f"Correct: {test_acc * 100.0:.2f}%")
