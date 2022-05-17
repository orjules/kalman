data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/simple_matrix_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/simple_matrix_filter/images/plot.png"
)

plot(
    data$Time, data$Height,
    ylim = range(-1:18),
    col = "red",
    type = "l",
    xlab = "Time",
    ylab = "Height and Velocity",
    main = "Kalman Filter simulation",
    sub = sprintf("Initial uncertainty: %2.1f, Measurement Uncertainty: %2.1f",
            data[1, "InitialUncertainty"],
            data[1, "MeasurementError"])
)
lines(data$Time, data$Measured, col = "black")
legend("topright",
        inset = 0.01,
        bty = "n",
        y.intersp = 1.3,
        legend = c("Corrected Height", "Measured Height"),
        col = c("red", "black"),
        pch = c(1, 1))

dev.off()
