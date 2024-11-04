import numpy as np
import scipy.io
import os
import matplotlib.pyplot as plt

class generate_inv:
    def __init__(self, file_path):
        self.data = scipy.io.loadmat(file_path)
        self.X = self.data["X"]
        self.V = self.data["V"]
        self.X_test = self.data["Xtest"]
        self.V_test = self.data["Vtest"]

        self.train_dir = 'train_shapes'
        self.test_dir = 'test_shapes'

        os.makedirs(self.train_dir, exist_ok=True)
        os.makedirs(self.test_dir, exist_ok=True)

    def save_shape(self, coords, file_name):
        """
        saves the shape in the grid as an image from 3D array (12x144x2) train
                                                              (12x48x2) test
               -2-1 0 1 2
            -2  # # # # #
            -1  #       #
             0  #       #
             1  #       #
             2  # # # # #
        """
        grid = np.ones((5, 5))

        coord_map = {
            -2: 0,
            -1: 1,
             0: 2,
             1: 3,
             2: 4
        }

        for coord in coords:
            x, y = coord
            if not np.isnan(x) and not np.isnan(y):
                grid_x = coord_map[int(x)]
                grid_y = coord_map[int(y)]
                grid[grid_x, grid_y] = 0

        fig, ax = plt.subplots(figsize=(5, 5))
        ax.imshow(grid, cmap='gray', vmin=0, vmax=1)
        ax.axis('off')
        plt.savefig(file_name, bbox_inches='tight', pad_inches=0, dpi=300)
        plt.close()

    def generate_shapes(self):
        for i in range(self.V.shape[1]):
            coords = self.V[:, i, :]
            file_name = os.path.join(self.train_dir, f'shape_{i+1}.png')
            self.save_shape(coords, file_name)
            print(f"saving train image {i+1} | {file_name}")

        for i in range(self.V_test.shape[1]):
            coords = self.V_test[:, i, :]
            file_name = os.path.join(self.test_dir, f'shape_{i+1}.png')
            self.save_shape(coords, file_name)
            print(f"saving test image {i+1} | {file_name}")

if __name__ == "__main__":
    file_path = "/home/ari/Desktop/Bayesian/BCL/chunk_learner_python/input_2001_Exp1.mat"
    inventory = generate_inv(file_path)
    inventory.generate_shapes()