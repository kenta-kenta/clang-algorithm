void freefall2(double v0, double theta) {
    double x, y, h, t;
    h = 0.1;
    for (int i = 1; h > 0; i++) {
        t = i * 0.1;
        x = t * v0 * cos(theta);
        y = -(9.8 / 2.0) * t * t + v0 * t * sin(theta);
        h = -(9.8 / 2.0) * (t + 0.1) * (t + 0.1) + v0 * (t + 0.1) * sin(theta);
        printf("%4.2f %4.2f\n", x, y);
    }
}

double newton(double x0, double delta, int limit) {
    double x = x0;
    int i;

    for (i = 0; i < limit; i++) {
        double fx = f(x);
        
        if (fabs(fx) < delta) {
            return x;
        }

        double gx = g(x);

        if (gx == 0) {
            return x;
        }

        x = x - fx / gx;
    }

    return x;
}