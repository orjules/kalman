data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_acc.png"
)

plot(
    data$Time, data$AccY,
    ylim = range(-1.3:2.3),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Acceleration in m/s^2",
    main = "Kalman Filter simulation - Acceleration",
    sub = sprintf("Error in measurement: %1.2f, Q for acceleration: %1.3f", data[1, "AccError"], data[1, "Q_acc"])
)
lines(data$Time, data$MeasAccY, col = "red")
lines(data$Time, data$MeasAccX, col = "black")
lines(data$Time, data$AccX, col = "orange")

legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State acceleration in y", "State acceleration in x", "Measured acceleration in y", "Measured acceleration in x"),
        col = c("blue", "orange", "red", "black"),
        pch = c(1, 1, 1, 1))

dev.off()