data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/scalar_filter/plotting/rust_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

plot(
    data$Iteration, data$Estimate,
    col = "red",
    type = "l",
    ylim = range(15:31),
    xlab = "Iteration",
    ylab = "Temperature",
    main = "Kalman Filter simulation",
    sub = sprintf("Initial uncertainty: %2.0f, Measurement Uncertainty: %1.1f",
            data[1, "Est_Uncert"],
            data[1, "Meas_Uncert"])
)
points(data$Iteration, data$Measurement, col = "blue")
abline(h = data$Real)
legend("top",
        inset = 0.01,
        bty = "n",
        y.intersp = 1.3,
        legend = c("Estimate", "Measurement", "Real Temperature"),
        col = c("red", "blue", "black"),
        pch = c(1, 1, 1))
