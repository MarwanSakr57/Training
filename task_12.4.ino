class PID {
  private:
    double input, output, smoothed_output;
    double prev_Error;
    double integ;
    double Kp, Ki, Kd;
    double alpha;
    unsigned long lastTime;

  public:
    // Constructor to initialize PID parameters
    PID(double p, double i, double d, double smoothing_factor) {
      Kp = p;
      Ki = i;
      Kd = d;
      alpha = smoothing_factor;
      prev_Error = 0;
      integ = 0;
      lastTime = millis();
      smoothed_output = 0;
    }

    // Compute PID output
    double compute(double setpoint, double current) {
      unsigned long currentTime = millis();
      double dt = (currentTime - lastTime) / 1000.0; // Convert ms to seconds

      double error = setpoint - current;
      double P = Kp * error;
      integ += error * dt;
      double I = Ki * integ;
      double derivative = (error - prev_Error) / dt;
      double D = Kd * derivative;
      double output = P + I + D;

      // Apply smoothing
      smoothed_output = (alpha * output) + ((1 - alpha) * smoothed_output);
      smoothed_output = constrain(smoothed_output, 0, 255);

      // Update for the next iteration
      prev_Error = error;
      lastTime = currentTime;

      return smoothed_output;
    }
};

PID pid(2.0, 5.0, 1.0, 0.3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  double input = analogRead(A1); // Read sensor value
  double output = pid.compute(1000, input); // Compute PID output
  analogWrite(A0, output); // Control output based on PID result
}
