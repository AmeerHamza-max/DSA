# 1732. Find the Highest Altitude

## Approach

The biker starts at altitude `0`. Each element in the `gain` array represents the change in altitude between two consecutive points.

We maintain:

* `curAltitude` → stores the current altitude.
* `maxAltitude` → stores the highest altitude reached so far.

### Algorithm

1. Initialize `curAltitude = 0` and `maxAltitude = 0`.
2. Traverse the `gain` array.
3. Add the current gain value to `curAltitude`.
4. Update `maxAltitude` if `curAltitude` is greater.
5. Return `maxAltitude`.

### Dry Run

**Input:**

```text
gain = [-5, 1, 5, 0, -7]
```

**Altitude Calculation:**

```text
Start: 0

0 + (-5) = -5
-5 + 1 = -4
-4 + 5 = 1
1 + 0 = 1
1 + (-7) = -6
```

Altitudes:

```text
[0, -5, -4, 1, 1, -6]
```

Highest Altitude:

```text
1
```

## Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

## Key Idea

This problem follows the **Running Sum (Prefix Sum)** pattern. We continuously calculate the current altitude and keep track of the maximum altitude encountered during traversal.
