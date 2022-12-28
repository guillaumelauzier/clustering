#include <iostream>
#include <vector>
#include <math.h>

// Define a data point with two features (x and y)
struct DataPoint {
    float x;
    float y;
};

// Calculate the Euclidean distance between two data points
float euclideanDistance(DataPoint a, DataPoint b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // Create a vector of data points
    std::vector<DataPoint> data = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    // Set the number of clusters (k)
    int k = 2;

    // Initialize the cluster centers as the first k data points
    std::vector<DataPoint> centers = {data[0], data[1]};

    // Initialize the cluster assignments for each data point
    std::vector<int> assignments(data.size());

    // Set the maximum number of iterations
    int maxIterations = 10;

    // Run the K-Means algorithm
    for (int iter = 0; iter < maxIterations; iter++) {
        // Assign each data point to the closest cluster center
        for (int i = 0; i < data.size(); i++) {
            float minDistance = INFINITY;
            int closestCenter = -1;
            for (int j = 0; j < centers.size(); j++) {
                float distance = euclideanDistance(data[i], centers[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestCenter = j;
                }
            }
            assignments[i] = closestCenter;
        }

        // Update the cluster centers as the mean of the data points in each cluster
        for (int j = 0; j < centers.size(); j++) {
            float sumX = 0;
            float sumY = 0;
            int count = 0;
            for (int i = 0; i < data.size(); i++) {
                if (assignments[i] == j) {
                    sumX += data[i].x;
                    sumY += data[i].y;
                    count++;
                }
            }
            centers[j].x = sumX / count;
            centers[j].y = sumY / count;
        }
    }

    // Print the final cluster assignments
    for (int i = 0; i < data.size(); i++) {
        std::cout << "Data point " << i << " is in cluster " << assignments[i] << std::endl;
    }

    return 0;
}

