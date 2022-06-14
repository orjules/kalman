data <- read.table(
    "./scalar_filter/plotting/rust_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "./scalar_filter/images/plot.png"
)

plot(
    data$Iteration, data$Estimate,
    col = "red",
    type = "l",
    ylim = range(15:31),
    xlab = "Iteration",
    ylab = "Temperature",
    main = "Kalman Filter simulation",
    sub = sprintf("Initial uncertainty: %2.1f, Measurement Uncertainty: %2.1f",
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

dev.off()