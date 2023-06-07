-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 15, 2023 at 02:55 PM
-- Server version: 10.4.25-MariaDB
-- PHP Version: 8.1.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `spp_lab`
--

-- --------------------------------------------------------

--
-- Table structure for table `t_cities`
--

CREATE TABLE `t_cities` (
  `id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL,
  `stop_ids` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL CHECK (json_valid(`stop_ids`)),
  `route_ids` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL CHECK (json_valid(`route_ids`)),
  `transport_ids` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL CHECK (json_valid(`transport_ids`)),
  `place_ids` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL CHECK (json_valid(`place_ids`))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `t_places`
--

CREATE TABLE `t_places` (
  `id` int(11) NOT NULL,
  `title` varchar(40) NOT NULL,
  `description` varchar(280) NOT NULL,
  `rating` float NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `t_places`
--

INSERT INTO `t_places` (`id`, `title`, `description`, `rating`, `pos_x`, `pos_y`) VALUES
(1, 'Updated', 'Welcome to a new place where you can spend all the time you want! We describe it as one of the places of all time. We also use ,./=_+-!@#$% when describing it.', 1, 100, 200),
(2, 'Брестская крепость', 'Брeстская крeпость — крепость в черте города Брест, у впадения реки Мухавец в Западный Буг, а также Тереспольской гмины Польши.', 4.8, 152.46, 594.97),
(3, 'Берестье', '«Берeстье» — уникальный археологический музей в городе Бресте, филиал Брестского областного краеведческого музея. Расположен на мысе, образуемом рекой Западный Буг и левым рукавом реки Мухавец, на территории Волынского укрепления Брестской крепости. ', 4.6, 159.05, 563.57),
(4, 'Свято-Николаевский гарнизонный собор', 'Свято-Николаевский гарнизонный собор — православный храм в городе Бресте, на территории Брестской крепости. Принадлежит к Брестской епархии Белорусского экзархата Русской православной церкви.', 4.9, 190, 406.78),
(5, 'Музей спасенных Художественных ценностей', 'Музей «Спасенные художественные ценности» — филиал Брестского областного историко-краеведческого музея. Расположен в историческом здании XX века.', 4.5, 941.52, 849.51);

-- --------------------------------------------------------

--
-- Table structure for table `t_routes`
--

CREATE TABLE `t_routes` (
  `id` int(11) NOT NULL,
  `stop_ids` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NOT NULL CHECK (json_valid(`stop_ids`)),
  `duration` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `t_routes`
--

INSERT INTO `t_routes` (`id`, `stop_ids`, `duration`) VALUES
(1, '1', 1);

-- --------------------------------------------------------

--
-- Table structure for table `t_stops`
--

CREATE TABLE `t_stops` (
  `id` int(11) NOT NULL,
  `title` varchar(40) NOT NULL,
  `pos_x` float NOT NULL,
  `pos_y` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `t_stops`
--

INSERT INTO `t_stops` (`id`, `title`, `pos_x`, `pos_y`) VALUES
(1, 'Stop title', 150, 200),
(2, 'Газоаппарат', 217.5, 285),
(3, 'Б. Космонавтов', 382.5, 627),
(4, 'ЦМТ', 866.7, 511.1),
(5, 'Орловская', 1434.9, 163.5),
(6, 'ЦГБ', 1806.3, 357.1),
(7, 'Крушинская', 1479.4, 439.7),
(8, 'Ковалёво', 1327, 1104.8),
(9, 'Цветотрон', 1160.3, 1142.9),
(10, 'М-Н Южный', 968.3, 1341.3),
(11, '4-й Форт', 781, 1261.9),
(12, 'Санта-53', 579.4, 1085.7),
(13, 'new stop123', 123.5, 123.6);

-- --------------------------------------------------------

--
-- Table structure for table `t_transports`
--

CREATE TABLE `t_transports` (
  `id` int(11) NOT NULL,
  `route_id` int(11) NOT NULL,
  `type` int(11) NOT NULL,
  `cost` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `t_transports`
--

INSERT INTO `t_transports` (`id`, `route_id`, `type`, `cost`) VALUES
(1, 1, 1, 100.49);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `t_cities`
--
ALTER TABLE `t_cities`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `t_places`
--
ALTER TABLE `t_places`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `t_routes`
--
ALTER TABLE `t_routes`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `t_stops`
--
ALTER TABLE `t_stops`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `t_transports`
--
ALTER TABLE `t_transports`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `t_cities`
--
ALTER TABLE `t_cities`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `t_places`
--
ALTER TABLE `t_places`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `t_routes`
--
ALTER TABLE `t_routes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `t_stops`
--
ALTER TABLE `t_stops`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `t_transports`
--
ALTER TABLE `t_transports`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
