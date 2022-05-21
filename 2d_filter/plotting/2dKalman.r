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
    data$Time, data$ActualAccX,
    ylim = range(-2:2),
    col = "blue",
    type = "l",
    xlab = "Time in s",
    ylab = "Acceleration in m/s^2",
    main = "Kalman Filter simulation - Acceleration",
    sub = sprintf("Error in measurement: %2.1f", data[1, "ErrorAcc"])
)
points(data$Time, data$ErroneousAccX, col = "#5c5cf9")
lines(data$Time, data$ActualAccY, col = "red")
points(data$Time, data$ErroneousAccY, col = "#f85e5e")
legend("topright",
        inset = 0.01,
        cex = 0.9,
        bty = "n",
        y.intersp = 1.3,
        legend = c("Real acceleration x", "Measured acceleration x",
                    "Real acceleration y", "Measured acceleration y"),
        col = c("blue", "#5c5cf9", "red", "#f85e5e"),
        pch = c(1, 1))

dev.off()


png(
    filename =
    "~/Documents/STAR/Kalman Filter/kalman/2d_filter/images/plot_rot.png"
)

plot(
    data$Time, data$ActualRot,
    ylim = range(-2:2),
    col = "black",
    type = "l",
    xlab = "Time in s",
    ylab = "Rotation speed in rad/s",
    main = "Kalman Filter simulation - Rotation speed",
    sub = sprintf("Error in measurement: %2.1f", data[1, "ErrorRot"])
)
points(data$Time, data$ErroneousRot, col = "red")
legend("topright",
        inset = 0.01,
        bty = "n",
        y.intersp = 1.3,
        legend = c("Real rotation speed", "Measured rotation speed"),
        col = c("black", "red"),
        pch = c(1, 1))

dev.off()