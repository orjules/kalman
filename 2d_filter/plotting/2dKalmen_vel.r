data <- read.table(
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/plotting/c_out.txt",
    header = TRUE,
    sep = ",",
    dec = ".")

png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_vel.png"
)

plot(
    data$Time, data$VelY,
    ylim = range(-1.5:1.5),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Velocity in m/s | Acceleration in m/s^2",
    main = "Kalman Filter simulation - Velocity",
    sub = sprintf("Error in measurement: %1.2f, Q for acceleration: %1.3f", data[1, "AccError"], data[1, "Q_acc"])
)
lines(data$Time, data$MeasAccY, col = "red")
lines(data$Time, data$MeasAccX, col = "black")
lines(data$Time, data$VelX, col = "orange")
abline(h=0)

legend("bottomleft",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("State velocity in y", "State velocity in x", "Measured acceleration in x", "Measured acceleration in y"),
        col = c("blue", "orange", "black", "red"),
        pch = c(1, 1, 1, 1))

dev.off()